// Copyright (c) Canaan Inc. All rights reserved.
// Licensed under the Apache license. See LICENSE file in the project root for full license information.

using System;
using Nncase.IR;
using Nncase.IR.Math;
using Onnx;
using static Nncase.IR.F.NN;
using static Nncase.IR.F.Math;

namespace Nncase.Importer
{
    public partial class OnnxImporter
    {
        private Expr VisitQuantizeLinear(in NodeProto op)
        {
            var (input, scale) = GetInputExprs(op, 0, 1);
            var bias = GetOptionInputExpr(op, 2, 0);
            if (scale is TensorConst scaleConst && bias is TensorConst biasConst)
            {
                return Quantize(input, new QuantParam(
                        biasConst.Value.ToScalar<int>(),
                        1 / scaleConst.Value.ToScalar<float>()),
                    GetOutputType(op));
            }

            throw new NotImplementedException("Onnx importer not impl for dynamic scale and bias");
        }
        
        private Expr VisitDequantizeLinear(in NodeProto op)
        {
            var (input, scale) = GetInputExprs(op, 0, 1);
            var bias = GetOptionInputExpr(op, 2, 0);
            if (scale is TensorConst scaleConst && bias is TensorConst biasConst)
            {
                var scaleV = scaleConst.Value.ToScalar<float>();
                var biasV = biasConst.Value.ToScalar<int>();
                return Dequantize(input, new QuantParam(
                        (int)(-biasV * scaleV),
                        scaleV),
                    GetOutputType(op));
            }

            throw new NotImplementedException("Onnx importer not impl for dynamic scale and bias");
        }
    }
}