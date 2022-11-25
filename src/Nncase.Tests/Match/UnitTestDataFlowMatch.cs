using System;
using System.Collections.Generic;
using Nncase;
using Nncase.IR;
using Nncase.PatternMatch;
using Nncase.Transform;
using Xunit;
using static Nncase.IR.F.Math;
using static Nncase.IR.F.Tensors;
using static Nncase.IR.TypePatternUtility;
using static Nncase.PatternMatch.F.Math;
using static Nncase.PatternMatch.F.NN;
using static Nncase.PatternMatch.Utility;

namespace Nncase.Tests.MatchTest;

public class UnitTestDataFlowMatch : TestFixture.UnitTestFixtrue
{
    //     [Fact]
    //     public void TestMatchDataFlowCallCommutive()
    //     {
    //         Var x = "x", y = "y";
    //         var addpat = IsBinary(BinaryOp.Add, IsVar(), IsVar());
    //         Assert.Single(Match(x + y, addpat));
    //         Assert.Single(Match(y + x, addpat));
    //         var mulpat = IsBinary(BinaryOp.Mul, IsVar(), IsVar());
    //         Assert.Single(Match(y * x, mulpat));
    //         Assert.Single(Match(x * y, mulpat));
    //     }

    //     [Fact]
    //     public void TestMatchDataFlowNoCallCommutive()
    //     {
    //         Var x = "x", y = "y";
    //         var addpat = IsBinary(BinaryOp.Sub, x, y);
    //         Assert.Single(Match(x - y, addpat));
    //         Assert.Empty(Match(y - x, addpat));
    //         var mulpat = IsBinary(BinaryOp.Div, x, y);
    //         Assert.Single(Match(x / y, mulpat));
    //         Assert.Empty(Match(y / x, mulpat));
    //     }

    //     [Fact]
    //     public void TestMatchDataFlowCall()
    //     {
    //         Var x = "x", y = "y";
    //         var addpat = IsBinary(BinaryOp.Add, IsWildcard(), IsWildcard());
    //         Assert.Single(Match(x + y, addpat));

    //         var callpat = IsWildcard();
    //         Assert.Single(Match(Square(x), callpat));
    //         Assert.Single(Match(x + y, callpat));
    //     }

    //     [Fact]
    //     public void TestNoMatchDataFlowFunc()
    //     {
    //         Var x = "x", y = "y";
    //         var pat = IsBinary(BinaryOp.Add, IsWildcard(), IsWildcard());
    //         Assert.Empty(Match(x - y, pat));
    //     }

    //     [Fact]
    //     public void TestMatchDataFlowConst()
    //     {
    //         Var x = "x", y = "y";
    //         var pat = IsBinary(BinaryOp.Sub, IsWildcard(), IsConst());
    //         Assert.Single(Match((x + y) - 100, pat));
    //     }

    //     [Fact]
    //     public void TestMatchDataFlowTuple()
    //     {
    //         Var x = "x", y = "y";
    //         var z = x + y;
    //         var tuple = new IR.Tuple(x, y, z);
    //         var tuplepat = IsTuple(IsVar(), IsWildcard(), IsBinary(BinaryOp.Add, IsWildcard(), IsWildcard()));

    //         Assert.Single(Match(tuple, tuplepat));

    //         var tuplepat2 = IsTuple();
    //         Assert.Single(Match(tuple, tuplepat2));
    //     }

    //     [Fact]
    //     public void TestNotMatchFoldConstCall()
    //     {
    //         var rule = new Transform.Rule.FoldConstCall();
    //         Var x = "x";
    //         var z = x + 1;
    //         Assert.Empty(Match(z, rule.Pattern));
    //     }

    //     [Fact]
    //     public void TestMatchFoldConstCallTwice()
    //     {
    //         var rule = new Transform.Rule.FoldConstCall();

    //         var z = Concat(new IR.Tuple((Const)2, (Const)1, (Const)2), 0);
    //         Assert.Single(Match(z, rule.Pattern));
    //         rule.Pattern.Clear();
    //         Assert.Single(Match(z, rule.Pattern));
    //     }

    //     [Fact]
    //     public void TestMatchFoldConstCallTwiceFalse()
    //     {
    //         var rule = new Transform.Rule.FoldConstCall();

    //         var z = Concat(new IR.Tuple((Var)"x", (Const)1, (Const)2), 0);
    //         Assert.Empty(Match(z, rule.Pattern));

    //         rule.Pattern.Clear();
    //         var z1 = Concat(new IR.Tuple((Const)4.0f, (Const)1.0f, (Const)1, (Const)2), 0);
    //         Assert.Single(Match(z1, rule.Pattern));
    //     }

    [Fact]
    public void TestMatchSameInput()
    {
        var input_pat = IsWildcard("input");
        var pat = IsBinary(BinaryOp.Mul, input_pat, IsSigmoid(input_pat));

        var input = (Expr)new[] { 1, 2, 3, 4 };
        var expr = input * IR.F.NN.Sigmoid(input);
        CompilerServices.TryMatch(expr, pat, out var res);
        var inp = res["input"];
    }

    private sealed class SimpleRule : IRewriteRule
    {
        public IPattern Pattern { get; } = PatternMatch.F.Math.IsBinary(BinaryOp.Add, IsWildcard("lhs"), IsWildcard("rhs"));

        public Expr? GetReplace(IMatchResult result, RunPassOptions options)
        {
            return (Expr)result["lhs"] - (Expr)result["rhs"];
        }

    }

    [Fact]
    public void TestMatchMultiBranch()
    {
        /*       
        - [ ] dataflow rewrite的pr有bug, 这里只考虑了被match到的节点修改后添加的rewritememo中
            1. 但是实际上如果 ((a - (b + c)) + (c * d)) 修改了b + c => b - c, 然后 b + c添加到rewrite memo中了,但是后续的a - (b+c)是mutator自动构造出来的, 此时在遍历老的expr的时候还是看到是a - (b+c), 并没有起到rewrite memo的作用
            2. 我理解应该是类似egraph, 如果遍历的是被替换过的新节点, 那么之间visit 新节点, 否则应该match老节点的类型, 然后leaf节点则匹配自动update 的ExprMemo中的节点.
         */
        var caseOptions = GetPassOptions();
        Expr a = 1;
        Expr b = 2;
        Expr c = 3;
        Expr d = 4;
        var pre = (a - (b + c)) + (c * d);
        CompilerServices.InferenceType(pre);

        var visitor = new DataFlowRewriteVisitor(new SimpleRule(), caseOptions);
        var post = visitor.Visit(pre);
        Assert.True(visitor.IsMutated);
        CompilerServices.DumpIR(post, "post", caseOptions.DumpDir);

        if (post is Call { Target: IR.Math.Binary { BinaryOp: BinaryOp.Sub } } root_call)
        {
            if (root_call[IR.Math.Binary.Lhs] is Call { Target: IR.Math.Binary { BinaryOp: BinaryOp.Sub } } lhs_call)
            {
                Assert.True(lhs_call[IR.Math.Binary.Rhs] is Call { Target: IR.Math.Binary { BinaryOp: BinaryOp.Sub } });
            }
        }
        else
            Assert.True(false);

    }

    sealed class UnaryFusion : Transform.Rules.Neutral.SingleInputFusion<IR.Math.Unary, IR.Math.Quantize, IR.Math.Dequantize>
    {
        public override string Name { get; } = "UnaryFusion";
    }

    sealed class TransposeFusion : Transform.Rules.Neutral.SingleInputFusion<IR.Tensors.Transpose, IR.Math.Quantize, IR.Math.Dequantize>
    {
        public override string Name { get; } = "TransposeFusion";
    }

    [Fact]
    public async void TestMultiFusion()
    {
        /* 
          之前fusion的逻辑是匹配 input -> op -> output 三个节点,然后在ouput上找到对应的 input替换成新的var
          修改过rewrite之后, 在get replace中得到 mutated input ->  op -> old output, 此时在old output上是找不到 mutated input的, 会报错.
          note 之前get replace的逻辑还是手动遍历节点, 我在想是不是应该调用matcher, 然后把rewrite memo传给它来操作?
         */
        var caseOptions = GetPassOptions();
        var input = new Var("input", new TensorType(DataTypes.Float32, new[] { 1, 24, 32, 3 }));
        Function pre;
        {
            var v0 = Quantize(input, new QuantParam(0, 1), DataTypes.BFloat16); // bf16[1,24,32,3]
            var v1 = Transpose(v0, new[] { 0, 3, 1, 2 }); // bf16[1,3,24,32]
            var v2 = Dequantize(v1, new QuantParam(0, 1), DataTypes.Float32); // f32[1,3,24,32]
            var v3 = v2 + IR.F.Random.Normal(DataTypes.Float32, 0, 1, 0, new[] { 1, 3, 24, 32 });
            var v4 = Quantize(v3, new QuantParam(0, 1), DataTypes.BFloat16); // bf16[1,3,24,32]
            var v5 = Unary(UnaryOp.Abs, v4); // bf16[1,3,24,32]
            var v6 = Dequantize(v5, new QuantParam(0, 1), DataTypes.Float32); // f32[1,3,24,32]
            var v7 = v6 - IR.F.Random.Normal(DataTypes.Float32, 0, 1, 0, new[] { 1, 3, 24, 32 });
            var v8 = Quantize(v7, new QuantParam(0, 1), DataTypes.BFloat16); // bf16[1,3,24,32]
            var v9 = Transpose(v8, new[] { 0, 2, 3, 1 }); // bf16[1,24,32,3]
            var v10 = Dequantize(v9, new QuantParam(0, 1), DataTypes.Float32); // f32[1,24,32,3]
            pre = new Function("main", v10, new Var[] { input });
        }
        CompilerServices.InferenceType(pre);

        var pass = new DataflowPass("Fusion")
            {
                new UnaryFusion(),
                new TransposeFusion(),
            };

        var post = await pass.RunAsync(pre, caseOptions);

    }
}
