/*
Copyright (c) 2014, Trail of Bits
All rights reserved.

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

  Redistributions of source code must retain the above copyright notice, this
  list of conditions and the following disclaimer.

  Redistributions in binary form must reproduce the above copyright notice, this  list of conditions and the following disclaimer in the documentation and/or
  other materials provided with the distribution.

  Neither the name of Trail of Bits nor the names of its
  contributors may be used to endorse or promote products derived from
  this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
#pragma once

#include <llvm/ADT/StringRef.h>
#include <llvm/IR/Instruction.h>
#include <llvm/IR/Function.h>
#include <map>


enum MCSemaRegs {
    EAX = llvm::X86::EAX,
    EBX = llvm::X86::EBX,
    ECX = llvm::X86::ECX,
    EDX = llvm::X86::EDX,
    ESI = llvm::X86::ESI,
    EDI = llvm::X86::EDI,
    ESP = llvm::X86::ESP,
    EBP = llvm::X86::EBP,
    CF = llvm::X86::NUM_TARGET_REGS+1,
    PF = llvm::X86::NUM_TARGET_REGS+2,
    AF = llvm::X86::NUM_TARGET_REGS+3,
    ZF = llvm::X86::NUM_TARGET_REGS+4,
    SF = llvm::X86::NUM_TARGET_REGS+5,
    OF = llvm::X86::NUM_TARGET_REGS+6,
    DF = llvm::X86::NUM_TARGET_REGS+7,
    ST0 = llvm::X86::ST0, 
    ST1 = llvm::X86::ST1, 
    ST2 = llvm::X86::ST2,
    ST3 = llvm::X86::ST3,
    ST4 = llvm::X86::ST4,
    ST5 = llvm::X86::ST5,
    ST6 = llvm::X86::ST6,
    ST7 = llvm::X86::ST7,
    FPU_B = llvm::X86::NUM_TARGET_REGS+8,
    FPU_C3 = llvm::X86::NUM_TARGET_REGS+9,
    FPU_TOP = llvm::X86::NUM_TARGET_REGS+10,
    FPU_C2 = llvm::X86::NUM_TARGET_REGS+11,
    FPU_C1 = llvm::X86::NUM_TARGET_REGS+12,
    FPU_C0 = llvm::X86::NUM_TARGET_REGS+13,
    FPU_ES = llvm::X86::NUM_TARGET_REGS+14,
    FPU_SF = llvm::X86::NUM_TARGET_REGS+15,
    FPU_PE = llvm::X86::NUM_TARGET_REGS+16,
    FPU_UE = llvm::X86::NUM_TARGET_REGS+17,
    FPU_OE = llvm::X86::NUM_TARGET_REGS+18,
    FPU_ZE = llvm::X86::NUM_TARGET_REGS+19,
    FPU_DE = llvm::X86::NUM_TARGET_REGS+20,
    FPU_IE = llvm::X86::NUM_TARGET_REGS+21,
    FPU_X = llvm::X86::NUM_TARGET_REGS+ 22, 
    FPU_RC = llvm::X86::NUM_TARGET_REGS+23,
    FPU_PC = llvm::X86::NUM_TARGET_REGS+24,
    FPU_PM = llvm::X86::NUM_TARGET_REGS+25,
    FPU_UM = llvm::X86::NUM_TARGET_REGS+26,
    FPU_OM = llvm::X86::NUM_TARGET_REGS+27,
    FPU_ZM = llvm::X86::NUM_TARGET_REGS+28,
    FPU_DM = llvm::X86::NUM_TARGET_REGS+29,
    FPU_IM = llvm::X86::NUM_TARGET_REGS+30,
    FPU_TAG = llvm::X86::NUM_TARGET_REGS+31,
    FPU_LASTIP_SEG = llvm::X86::NUM_TARGET_REGS+32, 
    FPU_LASTIP_OFF = llvm::X86::NUM_TARGET_REGS+33, 
    FPU_LASTDATA_SEG = llvm::X86::NUM_TARGET_REGS+34,
    FPU_LASTDATA_OFF = llvm::X86::NUM_TARGET_REGS+35,
    FPU_FOPCODE = llvm::X86::NUM_TARGET_REGS+36,
    XMM0 = llvm::X86::XMM0,
    XMM1 = llvm::X86::XMM1,
    XMM2 = llvm::X86::XMM2,
    XMM3 = llvm::X86::XMM3,
    XMM4 = llvm::X86::XMM4,
    XMM5 = llvm::X86::XMM5,
    XMM6 = llvm::X86::XMM6,
    XMM7 = llvm::X86::XMM7,
    STACK_BASE = llvm::X86::NUM_TARGET_REGS+37,
    STACK_LIMIT = llvm::X86::NUM_TARGET_REGS+38,
    MCSEMA_REGS_MAX = STACK_LIMIT+1
};

struct RegInfo {
    int position;
    llvm::StringRef name;
};

extern std::map<MCSemaRegs, RegInfo> REG_TO_OFFSET_MAP;

llvm::StringRef getRegisterName(MCSemaRegs reg);
int getRegisterOffset(MCSemaRegs reg);
llvm::Value *lookupLocal(llvm::Function *F, MCSemaRegs reg);
