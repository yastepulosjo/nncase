/* This file is generated by tools/stackvm_gen/IsaGen at 2021/3/25 17:43:41 +08:00.
 *
 * Copyright 2020 Canaan Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#pragma once
#include "../datatypes.h"

BEGIN_NS_NNCASE_RT_STACKVM

// Enums

enum class opcode_t
{
    NOP = 0x00,
    LDNULL = 0x01,
    LDC_I4 = 0x02,
    LDC_I4_0 = 0x03,
    LDC_I4_1 = 0x04,
    LDC_R4 = 0x05,
    LDIND_I1 = 0x06,
    LDIND_I2 = 0x07,
    LDIND_I4 = 0x08,
    LDIND_I = 0x09,
    LDIND_U1 = 0x0A,
    LDIND_U2 = 0x0B,
    LDIND_U4 = 0x0C,
    LDIND_U = 0x0D,
    LDIND_BR2 = 0x0E,
    LDIND_R4 = 0x0F,
    STIND_I1 = 0x10,
    STIND_I2 = 0x11,
    STIND_I4 = 0x12,
    STIND_I = 0x13,
    STIND_BR2 = 0x14,
    STIND_R4 = 0x15,
    LEA_GP = 0x16,
    LEA_BUFFER = 0x17,
    LDELEM_I1 = 0x18,
    LDELEM_I2 = 0x19,
    LDELEM_I4 = 0x1A,
    LDELEM_I = 0x1B,
    LDELEM_U1 = 0x1C,
    LDELEM_U2 = 0x1D,
    LDELEM_U4 = 0x1E,
    LDELEM_U = 0x1F,
    LDELEM_BR2 = 0x20,
    LDELEM_R4 = 0x21,
    STELEM_I1 = 0x22,
    STELEM_I2 = 0x23,
    STELEM_I4 = 0x24,
    STELEM_I = 0x25,
    STELEM_BR2 = 0x26,
    STELEM_R4 = 0x27,
    LDARG = 0x28,
    LDARG_0 = 0x29,
    LDARG_1 = 0x2A,
    LDARG_2 = 0x2B,
    LDARG_3 = 0x2C,
    LDARG_4 = 0x2D,
    LDARG_5 = 0x2E,
    DUP = 0x2F,
    POP = 0x30,
    STSHAPE = 0x31,
    STPADDINGS = 0x32,
    NEG = 0x33,
    ADD = 0x34,
    SUB = 0x35,
    MUL = 0x36,
    DIV = 0x37,
    DIV_U = 0x38,
    REM = 0x39,
    REM_U = 0x3A,
    AND = 0x3B,
    OR = 0x3C,
    XOR = 0x3D,
    NOT = 0x3E,
    SHL = 0x3F,
    SHR = 0x40,
    SHR_U = 0x41,
    CLT = 0x42,
    CLT_U = 0x43,
    CLE = 0x44,
    CLE_U = 0x45,
    CEQ = 0x46,
    CGE = 0x47,
    CGE_U = 0x48,
    CGT = 0x49,
    CGT_U = 0x4A,
    CNE = 0x4B,
    CONV_I1 = 0x4C,
    CONV_I2 = 0x4D,
    CONV_I4 = 0x4E,
    CONV_I = 0x4F,
    CONV_U1 = 0x50,
    CONV_U2 = 0x51,
    CONV_U4 = 0x52,
    CONV_U = 0x53,
    CONV_BR2 = 0x54,
    CONV_R4 = 0x55,
    BR = 0x56,
    BR_TRUE = 0x57,
    BR_FALSE = 0x58,
    RET = 0x59,
    CALL = 0x5A,
    ECALL = 0x5B,
    THROW = 0x5C,
    BREAK = 0x5D,
    TENSOR = 0x5E,
};

enum class tensor_function_t
{
    BATCH_TO_SPACE = 0x0000,
    BINARY = 0x0001,
    BROADCAST = 0x0002,
    CALL = 0x0003,
    CLAMP = 0x0004,
    CONCAT = 0x0005,
    CONV2D = 0x0006,
    CONV2D_TRANSPOSE = 0x0007,
    CONVERT = 0x0008,
    DEQUANTIZE = 0x0009,
    LOGISTIC = 0x000A,
    LUT1D = 0x000B,
    MATMUL = 0x000C,
    PAD = 0x000D,
    QUANTIZE = 0x000E,
    REDUCE = 0x000F,
    REDUCE_WINDOW2D = 0x0010,
    RESIZE_IMAGE = 0x0011,
    SLICE = 0x0012,
    SOFTMAX = 0x0013,
    SPACE_TO_BATCH = 0x0014,
    TAKE = 0x0015,
    TRANSPOSE = 0x0016,
    UNARY = 0x0017,
};

// Instructions

struct nop_op_t
{
    opcode_t opcode;

    nop_op_t(default_init_t) noexcept { }
    explicit nop_op_t() noexcept
        : opcode(opcode_t::NOP)
    {
    }
};

struct br_op_t
{
    opcode_t opcode;
    int32_t target;

    br_op_t(default_init_t) noexcept { }
    explicit br_op_t(int32_t target) noexcept
        : opcode(opcode_t::BR), target(target)
    {
    }
};

struct br_true_op_t
{
    opcode_t opcode;
    int32_t target;

    br_true_op_t(default_init_t) noexcept { }
    explicit br_true_op_t(int32_t target) noexcept
        : opcode(opcode_t::BR_TRUE), target(target)
    {
    }
};

struct br_false_op_t
{
    opcode_t opcode;
    int32_t target;

    br_false_op_t(default_init_t) noexcept { }
    explicit br_false_op_t(int32_t target) noexcept
        : opcode(opcode_t::BR_FALSE), target(target)
    {
    }
};

struct ret_op_t
{
    opcode_t opcode;

    ret_op_t(default_init_t) noexcept { }
    explicit ret_op_t() noexcept
        : opcode(opcode_t::RET)
    {
    }
};

struct call_op_t
{
    opcode_t opcode;
    uint8_t args;
    int32_t target;

    call_op_t(default_init_t) noexcept { }
    explicit call_op_t(uint8_t args, int32_t target) noexcept
        : opcode(opcode_t::CALL), args(args), target(target)
    {
    }
};

struct ecall_op_t
{
    opcode_t opcode;
    uint8_t args;

    ecall_op_t(default_init_t) noexcept { }
    explicit ecall_op_t(uint8_t args) noexcept
        : opcode(opcode_t::ECALL), args(args)
    {
    }
};

struct throw_op_t
{
    opcode_t opcode;

    throw_op_t(default_init_t) noexcept { }
    explicit throw_op_t() noexcept
        : opcode(opcode_t::THROW)
    {
    }
};

struct break_op_t
{
    opcode_t opcode;

    break_op_t(default_init_t) noexcept { }
    explicit break_op_t() noexcept
        : opcode(opcode_t::BREAK)
    {
    }
};

struct ldc_i4_op_t
{
    opcode_t opcode;
    int32_t imm;

    ldc_i4_op_t(default_init_t) noexcept { }
    explicit ldc_i4_op_t(int32_t imm) noexcept
        : opcode(opcode_t::LDC_I4), imm(imm)
    {
    }
};

struct ldnull_op_t
{
    opcode_t opcode;

    ldnull_op_t(default_init_t) noexcept { }
    explicit ldnull_op_t() noexcept
        : opcode(opcode_t::LDNULL)
    {
    }
};

struct ldc_i4_0_op_t
{
    opcode_t opcode;

    ldc_i4_0_op_t(default_init_t) noexcept { }
    explicit ldc_i4_0_op_t() noexcept
        : opcode(opcode_t::LDC_I4_0)
    {
    }
};

struct ldc_i4_1_op_t
{
    opcode_t opcode;

    ldc_i4_1_op_t(default_init_t) noexcept { }
    explicit ldc_i4_1_op_t() noexcept
        : opcode(opcode_t::LDC_I4_1)
    {
    }
};

struct ldc_r4_op_t
{
    opcode_t opcode;
    float imm;

    ldc_r4_op_t(default_init_t) noexcept { }
    explicit ldc_r4_op_t(float imm) noexcept
        : opcode(opcode_t::LDC_R4), imm(imm)
    {
    }
};

struct ldind_i1_op_t
{
    opcode_t opcode;

    ldind_i1_op_t(default_init_t) noexcept { }
    explicit ldind_i1_op_t() noexcept
        : opcode(opcode_t::LDIND_I1)
    {
    }
};

struct ldind_i2_op_t
{
    opcode_t opcode;

    ldind_i2_op_t(default_init_t) noexcept { }
    explicit ldind_i2_op_t() noexcept
        : opcode(opcode_t::LDIND_I2)
    {
    }
};

struct ldind_i4_op_t
{
    opcode_t opcode;

    ldind_i4_op_t(default_init_t) noexcept { }
    explicit ldind_i4_op_t() noexcept
        : opcode(opcode_t::LDIND_I4)
    {
    }
};

struct ldind_i_op_t
{
    opcode_t opcode;

    ldind_i_op_t(default_init_t) noexcept { }
    explicit ldind_i_op_t() noexcept
        : opcode(opcode_t::LDIND_I)
    {
    }
};

struct ldind_u1_op_t
{
    opcode_t opcode;

    ldind_u1_op_t(default_init_t) noexcept { }
    explicit ldind_u1_op_t() noexcept
        : opcode(opcode_t::LDIND_U1)
    {
    }
};

struct ldind_u2_op_t
{
    opcode_t opcode;

    ldind_u2_op_t(default_init_t) noexcept { }
    explicit ldind_u2_op_t() noexcept
        : opcode(opcode_t::LDIND_U2)
    {
    }
};

struct ldind_u4_op_t
{
    opcode_t opcode;

    ldind_u4_op_t(default_init_t) noexcept { }
    explicit ldind_u4_op_t() noexcept
        : opcode(opcode_t::LDIND_U4)
    {
    }
};

struct ldind_u_op_t
{
    opcode_t opcode;

    ldind_u_op_t(default_init_t) noexcept { }
    explicit ldind_u_op_t() noexcept
        : opcode(opcode_t::LDIND_U)
    {
    }
};

struct ldind_br2_op_t
{
    opcode_t opcode;

    ldind_br2_op_t(default_init_t) noexcept { }
    explicit ldind_br2_op_t() noexcept
        : opcode(opcode_t::LDIND_BR2)
    {
    }
};

struct ldind_r4_op_t
{
    opcode_t opcode;

    ldind_r4_op_t(default_init_t) noexcept { }
    explicit ldind_r4_op_t() noexcept
        : opcode(opcode_t::LDIND_R4)
    {
    }
};

struct stind_i1_op_t
{
    opcode_t opcode;

    stind_i1_op_t(default_init_t) noexcept { }
    explicit stind_i1_op_t() noexcept
        : opcode(opcode_t::STIND_I1)
    {
    }
};

struct stind_i2_op_t
{
    opcode_t opcode;

    stind_i2_op_t(default_init_t) noexcept { }
    explicit stind_i2_op_t() noexcept
        : opcode(opcode_t::STIND_I2)
    {
    }
};

struct stind_i4_op_t
{
    opcode_t opcode;

    stind_i4_op_t(default_init_t) noexcept { }
    explicit stind_i4_op_t() noexcept
        : opcode(opcode_t::STIND_I4)
    {
    }
};

struct stind_i_op_t
{
    opcode_t opcode;

    stind_i_op_t(default_init_t) noexcept { }
    explicit stind_i_op_t() noexcept
        : opcode(opcode_t::STIND_I)
    {
    }
};

struct stind_br2_op_t
{
    opcode_t opcode;

    stind_br2_op_t(default_init_t) noexcept { }
    explicit stind_br2_op_t() noexcept
        : opcode(opcode_t::STIND_BR2)
    {
    }
};

struct stind_r4_op_t
{
    opcode_t opcode;

    stind_r4_op_t(default_init_t) noexcept { }
    explicit stind_r4_op_t() noexcept
        : opcode(opcode_t::STIND_R4)
    {
    }
};

struct lea_gp_op_t
{
    opcode_t opcode;
    uint8_t gpid;
    int32_t offset;

    lea_gp_op_t(default_init_t) noexcept { }
    explicit lea_gp_op_t(uint8_t gpid, int32_t offset) noexcept
        : opcode(opcode_t::LEA_GP), gpid(gpid), offset(offset)
    {
    }
};

struct lea_buffer_op_t
{
    opcode_t opcode;
    memory_location_t location;
    uint8_t subres_id;
    uint32_t offset;

    lea_buffer_op_t(default_init_t) noexcept { }
    explicit lea_buffer_op_t(memory_location_t location, uint8_t subres_id, uint32_t offset) noexcept
        : opcode(opcode_t::LEA_BUFFER), location(location), subres_id(subres_id), offset(offset)
    {
    }
};

struct ldelem_i1_op_t
{
    opcode_t opcode;

    ldelem_i1_op_t(default_init_t) noexcept { }
    explicit ldelem_i1_op_t() noexcept
        : opcode(opcode_t::LDELEM_I1)
    {
    }
};

struct ldelem_i2_op_t
{
    opcode_t opcode;

    ldelem_i2_op_t(default_init_t) noexcept { }
    explicit ldelem_i2_op_t() noexcept
        : opcode(opcode_t::LDELEM_I2)
    {
    }
};

struct ldelem_i4_op_t
{
    opcode_t opcode;

    ldelem_i4_op_t(default_init_t) noexcept { }
    explicit ldelem_i4_op_t() noexcept
        : opcode(opcode_t::LDELEM_I4)
    {
    }
};

struct ldelem_i_op_t
{
    opcode_t opcode;

    ldelem_i_op_t(default_init_t) noexcept { }
    explicit ldelem_i_op_t() noexcept
        : opcode(opcode_t::LDELEM_I)
    {
    }
};

struct ldelem_u1_op_t
{
    opcode_t opcode;

    ldelem_u1_op_t(default_init_t) noexcept { }
    explicit ldelem_u1_op_t() noexcept
        : opcode(opcode_t::LDELEM_U1)
    {
    }
};

struct ldelem_u2_op_t
{
    opcode_t opcode;

    ldelem_u2_op_t(default_init_t) noexcept { }
    explicit ldelem_u2_op_t() noexcept
        : opcode(opcode_t::LDELEM_U2)
    {
    }
};

struct ldelem_u4_op_t
{
    opcode_t opcode;

    ldelem_u4_op_t(default_init_t) noexcept { }
    explicit ldelem_u4_op_t() noexcept
        : opcode(opcode_t::LDELEM_U4)
    {
    }
};

struct ldelem_u_op_t
{
    opcode_t opcode;

    ldelem_u_op_t(default_init_t) noexcept { }
    explicit ldelem_u_op_t() noexcept
        : opcode(opcode_t::LDELEM_U)
    {
    }
};

struct ldelem_br2_op_t
{
    opcode_t opcode;

    ldelem_br2_op_t(default_init_t) noexcept { }
    explicit ldelem_br2_op_t() noexcept
        : opcode(opcode_t::LDELEM_BR2)
    {
    }
};

struct ldelem_r4_op_t
{
    opcode_t opcode;

    ldelem_r4_op_t(default_init_t) noexcept { }
    explicit ldelem_r4_op_t() noexcept
        : opcode(opcode_t::LDELEM_R4)
    {
    }
};

struct stelem_i1_op_t
{
    opcode_t opcode;

    stelem_i1_op_t(default_init_t) noexcept { }
    explicit stelem_i1_op_t() noexcept
        : opcode(opcode_t::STELEM_I1)
    {
    }
};

struct stelem_i2_op_t
{
    opcode_t opcode;

    stelem_i2_op_t(default_init_t) noexcept { }
    explicit stelem_i2_op_t() noexcept
        : opcode(opcode_t::STELEM_I2)
    {
    }
};

struct stelem_i4_op_t
{
    opcode_t opcode;

    stelem_i4_op_t(default_init_t) noexcept { }
    explicit stelem_i4_op_t() noexcept
        : opcode(opcode_t::STELEM_I4)
    {
    }
};

struct stelem_i_op_t
{
    opcode_t opcode;

    stelem_i_op_t(default_init_t) noexcept { }
    explicit stelem_i_op_t() noexcept
        : opcode(opcode_t::STELEM_I)
    {
    }
};

struct stelem_br2_op_t
{
    opcode_t opcode;

    stelem_br2_op_t(default_init_t) noexcept { }
    explicit stelem_br2_op_t() noexcept
        : opcode(opcode_t::STELEM_BR2)
    {
    }
};

struct stelem_r4_op_t
{
    opcode_t opcode;

    stelem_r4_op_t(default_init_t) noexcept { }
    explicit stelem_r4_op_t() noexcept
        : opcode(opcode_t::STELEM_R4)
    {
    }
};

struct ldarg_op_t
{
    opcode_t opcode;
    uint32_t index;

    ldarg_op_t(default_init_t) noexcept { }
    explicit ldarg_op_t(uint32_t index) noexcept
        : opcode(opcode_t::LDARG), index(index)
    {
    }
};

struct ldarg_0_op_t
{
    opcode_t opcode;

    ldarg_0_op_t(default_init_t) noexcept { }
    explicit ldarg_0_op_t() noexcept
        : opcode(opcode_t::LDARG_0)
    {
    }
};

struct ldarg_1_op_t
{
    opcode_t opcode;

    ldarg_1_op_t(default_init_t) noexcept { }
    explicit ldarg_1_op_t() noexcept
        : opcode(opcode_t::LDARG_1)
    {
    }
};

struct ldarg_2_op_t
{
    opcode_t opcode;

    ldarg_2_op_t(default_init_t) noexcept { }
    explicit ldarg_2_op_t() noexcept
        : opcode(opcode_t::LDARG_2)
    {
    }
};

struct ldarg_3_op_t
{
    opcode_t opcode;

    ldarg_3_op_t(default_init_t) noexcept { }
    explicit ldarg_3_op_t() noexcept
        : opcode(opcode_t::LDARG_3)
    {
    }
};

struct ldarg_4_op_t
{
    opcode_t opcode;

    ldarg_4_op_t(default_init_t) noexcept { }
    explicit ldarg_4_op_t() noexcept
        : opcode(opcode_t::LDARG_4)
    {
    }
};

struct ldarg_5_op_t
{
    opcode_t opcode;

    ldarg_5_op_t(default_init_t) noexcept { }
    explicit ldarg_5_op_t() noexcept
        : opcode(opcode_t::LDARG_5)
    {
    }
};

struct stshape_op_t
{
    opcode_t opcode;
    uint8_t rshape;
    uint8_t rank;

    stshape_op_t(default_init_t) noexcept { }
    explicit stshape_op_t(uint8_t rshape, uint8_t rank) noexcept
        : opcode(opcode_t::STSHAPE), rshape(rshape), rank(rank)
    {
    }
};

struct stpaddings_op_t
{
    opcode_t opcode;
    uint8_t rpaddings;
    uint8_t rank;

    stpaddings_op_t(default_init_t) noexcept { }
    explicit stpaddings_op_t(uint8_t rpaddings, uint8_t rank) noexcept
        : opcode(opcode_t::STPADDINGS), rpaddings(rpaddings), rank(rank)
    {
    }
};

struct dup_op_t
{
    opcode_t opcode;

    dup_op_t(default_init_t) noexcept { }
    explicit dup_op_t() noexcept
        : opcode(opcode_t::DUP)
    {
    }
};

struct pop_op_t
{
    opcode_t opcode;

    pop_op_t(default_init_t) noexcept { }
    explicit pop_op_t() noexcept
        : opcode(opcode_t::POP)
    {
    }
};

struct neg_op_t
{
    opcode_t opcode;

    neg_op_t(default_init_t) noexcept { }
    explicit neg_op_t() noexcept
        : opcode(opcode_t::NEG)
    {
    }
};

struct add_op_t
{
    opcode_t opcode;

    add_op_t(default_init_t) noexcept { }
    explicit add_op_t() noexcept
        : opcode(opcode_t::ADD)
    {
    }
};

struct sub_op_t
{
    opcode_t opcode;

    sub_op_t(default_init_t) noexcept { }
    explicit sub_op_t() noexcept
        : opcode(opcode_t::SUB)
    {
    }
};

struct mul_op_t
{
    opcode_t opcode;

    mul_op_t(default_init_t) noexcept { }
    explicit mul_op_t() noexcept
        : opcode(opcode_t::MUL)
    {
    }
};

struct div_op_t
{
    opcode_t opcode;

    div_op_t(default_init_t) noexcept { }
    explicit div_op_t() noexcept
        : opcode(opcode_t::DIV)
    {
    }
};

struct div_u_op_t
{
    opcode_t opcode;

    div_u_op_t(default_init_t) noexcept { }
    explicit div_u_op_t() noexcept
        : opcode(opcode_t::DIV_U)
    {
    }
};

struct rem_op_t
{
    opcode_t opcode;

    rem_op_t(default_init_t) noexcept { }
    explicit rem_op_t() noexcept
        : opcode(opcode_t::REM)
    {
    }
};

struct rem_u_op_t
{
    opcode_t opcode;

    rem_u_op_t(default_init_t) noexcept { }
    explicit rem_u_op_t() noexcept
        : opcode(opcode_t::REM_U)
    {
    }
};

struct and_op_t
{
    opcode_t opcode;

    and_op_t(default_init_t) noexcept { }
    explicit and_op_t() noexcept
        : opcode(opcode_t::AND)
    {
    }
};

struct or_op_t
{
    opcode_t opcode;

    or_op_t(default_init_t) noexcept { }
    explicit or_op_t() noexcept
        : opcode(opcode_t::OR)
    {
    }
};

struct xor_op_t
{
    opcode_t opcode;

    xor_op_t(default_init_t) noexcept { }
    explicit xor_op_t() noexcept
        : opcode(opcode_t::XOR)
    {
    }
};

struct not_op_t
{
    opcode_t opcode;

    not_op_t(default_init_t) noexcept { }
    explicit not_op_t() noexcept
        : opcode(opcode_t::NOT)
    {
    }
};

struct shl_op_t
{
    opcode_t opcode;

    shl_op_t(default_init_t) noexcept { }
    explicit shl_op_t() noexcept
        : opcode(opcode_t::SHL)
    {
    }
};

struct shr_op_t
{
    opcode_t opcode;

    shr_op_t(default_init_t) noexcept { }
    explicit shr_op_t() noexcept
        : opcode(opcode_t::SHR)
    {
    }
};

struct shr_u_op_t
{
    opcode_t opcode;

    shr_u_op_t(default_init_t) noexcept { }
    explicit shr_u_op_t() noexcept
        : opcode(opcode_t::SHR_U)
    {
    }
};

struct clt_op_t
{
    opcode_t opcode;

    clt_op_t(default_init_t) noexcept { }
    explicit clt_op_t() noexcept
        : opcode(opcode_t::CLT)
    {
    }
};

struct clt_u_op_t
{
    opcode_t opcode;

    clt_u_op_t(default_init_t) noexcept { }
    explicit clt_u_op_t() noexcept
        : opcode(opcode_t::CLT_U)
    {
    }
};

struct cle_op_t
{
    opcode_t opcode;

    cle_op_t(default_init_t) noexcept { }
    explicit cle_op_t() noexcept
        : opcode(opcode_t::CLE)
    {
    }
};

struct cle_u_op_t
{
    opcode_t opcode;

    cle_u_op_t(default_init_t) noexcept { }
    explicit cle_u_op_t() noexcept
        : opcode(opcode_t::CLE_U)
    {
    }
};

struct ceq_op_t
{
    opcode_t opcode;

    ceq_op_t(default_init_t) noexcept { }
    explicit ceq_op_t() noexcept
        : opcode(opcode_t::CEQ)
    {
    }
};

struct cge_op_t
{
    opcode_t opcode;

    cge_op_t(default_init_t) noexcept { }
    explicit cge_op_t() noexcept
        : opcode(opcode_t::CGE)
    {
    }
};

struct cge_u_op_t
{
    opcode_t opcode;

    cge_u_op_t(default_init_t) noexcept { }
    explicit cge_u_op_t() noexcept
        : opcode(opcode_t::CGE_U)
    {
    }
};

struct cgt_op_t
{
    opcode_t opcode;

    cgt_op_t(default_init_t) noexcept { }
    explicit cgt_op_t() noexcept
        : opcode(opcode_t::CGT)
    {
    }
};

struct cgt_u_op_t
{
    opcode_t opcode;

    cgt_u_op_t(default_init_t) noexcept { }
    explicit cgt_u_op_t() noexcept
        : opcode(opcode_t::CGT_U)
    {
    }
};

struct cne_op_t
{
    opcode_t opcode;

    cne_op_t(default_init_t) noexcept { }
    explicit cne_op_t() noexcept
        : opcode(opcode_t::CNE)
    {
    }
};

struct conv_i1_op_t
{
    opcode_t opcode;

    conv_i1_op_t(default_init_t) noexcept { }
    explicit conv_i1_op_t() noexcept
        : opcode(opcode_t::CONV_I1)
    {
    }
};

struct conv_i2_op_t
{
    opcode_t opcode;

    conv_i2_op_t(default_init_t) noexcept { }
    explicit conv_i2_op_t() noexcept
        : opcode(opcode_t::CONV_I2)
    {
    }
};

struct conv_i4_op_t
{
    opcode_t opcode;

    conv_i4_op_t(default_init_t) noexcept { }
    explicit conv_i4_op_t() noexcept
        : opcode(opcode_t::CONV_I4)
    {
    }
};

struct conv_i_op_t
{
    opcode_t opcode;

    conv_i_op_t(default_init_t) noexcept { }
    explicit conv_i_op_t() noexcept
        : opcode(opcode_t::CONV_I)
    {
    }
};

struct conv_u1_op_t
{
    opcode_t opcode;

    conv_u1_op_t(default_init_t) noexcept { }
    explicit conv_u1_op_t() noexcept
        : opcode(opcode_t::CONV_U1)
    {
    }
};

struct conv_u2_op_t
{
    opcode_t opcode;

    conv_u2_op_t(default_init_t) noexcept { }
    explicit conv_u2_op_t() noexcept
        : opcode(opcode_t::CONV_U2)
    {
    }
};

struct conv_u4_op_t
{
    opcode_t opcode;

    conv_u4_op_t(default_init_t) noexcept { }
    explicit conv_u4_op_t() noexcept
        : opcode(opcode_t::CONV_U4)
    {
    }
};

struct conv_u_op_t
{
    opcode_t opcode;

    conv_u_op_t(default_init_t) noexcept { }
    explicit conv_u_op_t() noexcept
        : opcode(opcode_t::CONV_U)
    {
    }
};

struct conv_br2_op_t
{
    opcode_t opcode;

    conv_br2_op_t(default_init_t) noexcept { }
    explicit conv_br2_op_t() noexcept
        : opcode(opcode_t::CONV_BR2)
    {
    }
};

struct conv_r4_op_t
{
    opcode_t opcode;

    conv_r4_op_t(default_init_t) noexcept { }
    explicit conv_r4_op_t() noexcept
        : opcode(opcode_t::CONV_R4)
    {
    }
};

struct tensor_batch_to_space_op_t
{
    opcode_t opcode;
    tensor_function_t funct;
    datatype_t datatype;
    uint8_t rshape_src;
    uint8_t rstride_src;
    uint8_t rstride_dest;
    uint8_t rshape_block;
    uint8_t rpad_crops;

    tensor_batch_to_space_op_t(default_init_t) noexcept { }
    explicit tensor_batch_to_space_op_t(datatype_t datatype, uint8_t rshape_src, uint8_t rstride_src, uint8_t rstride_dest, uint8_t rshape_block, uint8_t rpad_crops) noexcept
        : opcode(opcode_t::TENSOR), funct(tensor_function_t::BATCH_TO_SPACE), datatype(datatype), rshape_src(rshape_src), rstride_src(rstride_src), rstride_dest(rstride_dest), rshape_block(rshape_block), rpad_crops(rpad_crops)
    {
    }
};

struct tensor_broadcast_op_t
{
    opcode_t opcode;
    tensor_function_t funct;
    datatype_t datatype;
    uint8_t rshape_src;
    uint8_t rstride_src;
    uint8_t rshape_dest;
    uint8_t rstride_dest;

    tensor_broadcast_op_t(default_init_t) noexcept { }
    explicit tensor_broadcast_op_t(datatype_t datatype, uint8_t rshape_src, uint8_t rstride_src, uint8_t rshape_dest, uint8_t rstride_dest) noexcept
        : opcode(opcode_t::TENSOR), funct(tensor_function_t::BROADCAST), datatype(datatype), rshape_src(rshape_src), rstride_src(rstride_src), rshape_dest(rshape_dest), rstride_dest(rstride_dest)
    {
    }
};

struct tensor_binary_op_t
{
    opcode_t opcode;
    tensor_function_t funct;
    datatype_t datatype;
    uint8_t rshape_src1;
    uint8_t rstride_src1;
    uint8_t rshape_src2;
    uint8_t rstride_src2;
    uint8_t rstride_dest;
    binary_op_t binary_op;
    float fused_clamp_low;
    float fused_clamp_high;

    tensor_binary_op_t(default_init_t) noexcept { }
    explicit tensor_binary_op_t(datatype_t datatype, uint8_t rshape_src1, uint8_t rstride_src1, uint8_t rshape_src2, uint8_t rstride_src2, uint8_t rstride_dest, binary_op_t binary_op, float fused_clamp_low, float fused_clamp_high) noexcept
        : opcode(opcode_t::TENSOR), funct(tensor_function_t::BINARY), datatype(datatype), rshape_src1(rshape_src1), rstride_src1(rstride_src1), rshape_src2(rshape_src2), rstride_src2(rstride_src2), rstride_dest(rstride_dest), binary_op(binary_op), fused_clamp_low(fused_clamp_low), fused_clamp_high(fused_clamp_high)
    {
    }
};

struct tensor_call_op_t
{
    opcode_t opcode;
    tensor_function_t funct;
    uint32_t module_id;
    uint8_t num_src;
    uint8_t num_dst;

    tensor_call_op_t(default_init_t) noexcept { }
    explicit tensor_call_op_t(uint32_t module_id, uint8_t num_src, uint8_t num_dst) noexcept
        : opcode(opcode_t::TENSOR), funct(tensor_function_t::CALL), module_id(module_id), num_src(num_src), num_dst(num_dst)
    {
    }
};

struct tensor_concat_op_t
{
    opcode_t opcode;
    tensor_function_t funct;
    datatype_t datatype;
    uint8_t num_src;
    uint8_t axis;
    uint8_t rshape_dims;
    uint8_t rshape_dest;
    uint8_t rstride_dest;

    tensor_concat_op_t(default_init_t) noexcept { }
    explicit tensor_concat_op_t(datatype_t datatype, uint8_t num_src, uint8_t axis, uint8_t rshape_dims, uint8_t rshape_dest, uint8_t rstride_dest) noexcept
        : opcode(opcode_t::TENSOR), funct(tensor_function_t::CONCAT), datatype(datatype), num_src(num_src), axis(axis), rshape_dims(rshape_dims), rshape_dest(rshape_dest), rstride_dest(rstride_dest)
    {
    }
};

struct tensor_conv2d_op_t
{
    opcode_t opcode;
    tensor_function_t funct;
    datatype_t datatype;
    uint8_t rshape_src;
    uint8_t rstride_src;
    uint8_t rshape_kernel;
    uint8_t rstride_kernel;
    uint8_t rstride_bias;
    uint8_t rstride_dest;
    uint16_t groups;
    uint16_t stride_h;
    uint16_t stride_w;
    uint16_t dilation_h;
    uint16_t dilation_w;
    float fused_clamp_low;
    float fused_clamp_high;

    tensor_conv2d_op_t(default_init_t) noexcept { }
    explicit tensor_conv2d_op_t(datatype_t datatype, uint8_t rshape_src, uint8_t rstride_src, uint8_t rshape_kernel, uint8_t rstride_kernel, uint8_t rstride_bias, uint8_t rstride_dest, uint16_t groups, uint16_t stride_h, uint16_t stride_w, uint16_t dilation_h, uint16_t dilation_w, float fused_clamp_low, float fused_clamp_high) noexcept
        : opcode(opcode_t::TENSOR), funct(tensor_function_t::CONV2D), datatype(datatype), rshape_src(rshape_src), rstride_src(rstride_src), rshape_kernel(rshape_kernel), rstride_kernel(rstride_kernel), rstride_bias(rstride_bias), rstride_dest(rstride_dest), groups(groups), stride_h(stride_h), stride_w(stride_w), dilation_h(dilation_h), dilation_w(dilation_w), fused_clamp_low(fused_clamp_low), fused_clamp_high(fused_clamp_high)
    {
    }
};

struct tensor_convert_op_t
{
    opcode_t opcode;
    tensor_function_t funct;
    datatype_t in_datatype;
    datatype_t dst_datatype;
    uint8_t rshape_src;
    uint8_t rstride_src;
    uint8_t rstride_dest;

    tensor_convert_op_t(default_init_t) noexcept { }
    explicit tensor_convert_op_t(datatype_t in_datatype, datatype_t dst_datatype, uint8_t rshape_src, uint8_t rstride_src, uint8_t rstride_dest) noexcept
        : opcode(opcode_t::TENSOR), funct(tensor_function_t::CONVERT), in_datatype(in_datatype), dst_datatype(dst_datatype), rshape_src(rshape_src), rstride_src(rstride_src), rstride_dest(rstride_dest)
    {
    }
};

struct tensor_dequantize_op_t
{
    opcode_t opcode;
    tensor_function_t funct;
    datatype_t in_datatype;
    datatype_t dst_datatype;
    uint8_t rshape_src;
    uint8_t rstride_src;
    uint8_t rstride_dest;

    tensor_dequantize_op_t(default_init_t) noexcept { }
    explicit tensor_dequantize_op_t(datatype_t in_datatype, datatype_t dst_datatype, uint8_t rshape_src, uint8_t rstride_src, uint8_t rstride_dest) noexcept
        : opcode(opcode_t::TENSOR), funct(tensor_function_t::DEQUANTIZE), in_datatype(in_datatype), dst_datatype(dst_datatype), rshape_src(rshape_src), rstride_src(rstride_src), rstride_dest(rstride_dest)
    {
    }
};

struct tensor_pad_op_t
{
    opcode_t opcode;
    tensor_function_t funct;
    datatype_t datatype;
    uint8_t rshape_src;
    uint8_t rstride_src;
    uint8_t rstride_dest;
    uint8_t rpaddings;
    pad_mode_t pad_mode;

    tensor_pad_op_t(default_init_t) noexcept { }
    explicit tensor_pad_op_t(datatype_t datatype, uint8_t rshape_src, uint8_t rstride_src, uint8_t rstride_dest, uint8_t rpaddings, pad_mode_t pad_mode) noexcept
        : opcode(opcode_t::TENSOR), funct(tensor_function_t::PAD), datatype(datatype), rshape_src(rshape_src), rstride_src(rstride_src), rstride_dest(rstride_dest), rpaddings(rpaddings), pad_mode(pad_mode)
    {
    }
};

struct tensor_quantize_op_t
{
    opcode_t opcode;
    tensor_function_t funct;
    datatype_t in_datatype;
    datatype_t dst_datatype;
    uint8_t rshape_src;
    uint8_t rstride_src;
    uint8_t rstride_dest;

    tensor_quantize_op_t(default_init_t) noexcept { }
    explicit tensor_quantize_op_t(datatype_t in_datatype, datatype_t dst_datatype, uint8_t rshape_src, uint8_t rstride_src, uint8_t rstride_dest) noexcept
        : opcode(opcode_t::TENSOR), funct(tensor_function_t::QUANTIZE), in_datatype(in_datatype), dst_datatype(dst_datatype), rshape_src(rshape_src), rstride_src(rstride_src), rstride_dest(rstride_dest)
    {
    }
};

struct tensor_reduce_op_t
{
    opcode_t opcode;
    tensor_function_t funct;
    datatype_t datatype;
    uint8_t rshape_src;
    uint8_t rstride_src;
    uint8_t rstride_dest;
    reduce_op_t reduce_op;
    uint8_t rshape_axis;
    bool keep_dims;

    tensor_reduce_op_t(default_init_t) noexcept { }
    explicit tensor_reduce_op_t(datatype_t datatype, uint8_t rshape_src, uint8_t rstride_src, uint8_t rstride_dest, reduce_op_t reduce_op, uint8_t rshape_axis, bool keep_dims) noexcept
        : opcode(opcode_t::TENSOR), funct(tensor_function_t::REDUCE), datatype(datatype), rshape_src(rshape_src), rstride_src(rstride_src), rstride_dest(rstride_dest), reduce_op(reduce_op), rshape_axis(rshape_axis), keep_dims(keep_dims)
    {
    }
};

struct tensor_reduce_window2d_op_t
{
    opcode_t opcode;
    tensor_function_t funct;
    datatype_t datatype;
    reduce_op_t reduce_op;
    uint8_t rshape_src;
    uint8_t rstride_src;
    uint8_t rstride_dest;
    uint16_t filter_h;
    uint16_t filter_w;
    uint16_t stride_h;
    uint16_t stride_w;
    uint16_t dilation_h;
    uint16_t dilation_w;
    float fused_clamp_low;
    float fused_clamp_high;

    tensor_reduce_window2d_op_t(default_init_t) noexcept { }
    explicit tensor_reduce_window2d_op_t(datatype_t datatype, reduce_op_t reduce_op, uint8_t rshape_src, uint8_t rstride_src, uint8_t rstride_dest, uint16_t filter_h, uint16_t filter_w, uint16_t stride_h, uint16_t stride_w, uint16_t dilation_h, uint16_t dilation_w, float fused_clamp_low, float fused_clamp_high) noexcept
        : opcode(opcode_t::TENSOR), funct(tensor_function_t::REDUCE_WINDOW2D), datatype(datatype), reduce_op(reduce_op), rshape_src(rshape_src), rstride_src(rstride_src), rstride_dest(rstride_dest), filter_h(filter_h), filter_w(filter_w), stride_h(stride_h), stride_w(stride_w), dilation_h(dilation_h), dilation_w(dilation_w), fused_clamp_low(fused_clamp_low), fused_clamp_high(fused_clamp_high)
    {
    }
};

struct tensor_slice_op_t
{
    opcode_t opcode;
    tensor_function_t funct;
    datatype_t datatype;
    uint8_t rshape_src;
    uint8_t rstride_src;
    uint8_t rstride_dest;
    uint8_t rbegins;
    uint8_t rends;
    uint8_t rstrides;

    tensor_slice_op_t(default_init_t) noexcept { }
    explicit tensor_slice_op_t(datatype_t datatype, uint8_t rshape_src, uint8_t rstride_src, uint8_t rstride_dest, uint8_t rbegins, uint8_t rends, uint8_t rstrides) noexcept
        : opcode(opcode_t::TENSOR), funct(tensor_function_t::SLICE), datatype(datatype), rshape_src(rshape_src), rstride_src(rstride_src), rstride_dest(rstride_dest), rbegins(rbegins), rends(rends), rstrides(rstrides)
    {
    }
};

struct tensor_unary_op_t
{
    opcode_t opcode;
    tensor_function_t funct;
    datatype_t datatype;
    uint8_t rshape_src;
    uint8_t rstride_src;
    uint8_t rstride_dest;
    unary_op_t unary_op;

    tensor_unary_op_t(default_init_t) noexcept { }
    explicit tensor_unary_op_t(datatype_t datatype, uint8_t rshape_src, uint8_t rstride_src, uint8_t rstride_dest, unary_op_t unary_op) noexcept
        : opcode(opcode_t::TENSOR), funct(tensor_function_t::UNARY), datatype(datatype), rshape_src(rshape_src), rstride_src(rstride_src), rstride_dest(rstride_dest), unary_op(unary_op)
    {
    }
};

struct tensor_transpose_op_t
{
    opcode_t opcode;
    tensor_function_t funct;
    datatype_t datatype;
    uint8_t rshape_src;
    uint8_t rstride_src;
    uint8_t rstride_dest;
    uint8_t rshape_perm;

    tensor_transpose_op_t(default_init_t) noexcept { }
    explicit tensor_transpose_op_t(datatype_t datatype, uint8_t rshape_src, uint8_t rstride_src, uint8_t rstride_dest, uint8_t rshape_perm) noexcept
        : opcode(opcode_t::TENSOR), funct(tensor_function_t::TRANSPOSE), datatype(datatype), rshape_src(rshape_src), rstride_src(rstride_src), rstride_dest(rstride_dest), rshape_perm(rshape_perm)
    {
    }
};

END_NS_NNCASE_RT_STACKVM
