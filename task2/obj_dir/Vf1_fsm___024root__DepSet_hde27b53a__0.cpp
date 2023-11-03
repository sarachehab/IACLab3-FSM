// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vf1_fsm.h for the primary calling header

#include "verilated.h"

#include "Vf1_fsm__Syms.h"
#include "Vf1_fsm___024root.h"

void Vf1_fsm___024root___eval_act(Vf1_fsm___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vf1_fsm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vf1_fsm___024root___eval_act\n"); );
}

VL_INLINE_OPT void Vf1_fsm___024root___nba_sequent__TOP__0(Vf1_fsm___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vf1_fsm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vf1_fsm___024root___nba_sequent__TOP__0\n"); );
    // Body
    if (vlSelf->rst) {
        vlSelf->f1_fsm__DOT__current_state = 0U;
    } else if (vlSelf->en) {
        vlSelf->f1_fsm__DOT__current_state = vlSelf->f1_fsm__DOT__next_state;
    }
    if (((((((((0U == vlSelf->f1_fsm__DOT__current_state) 
               | (1U == vlSelf->f1_fsm__DOT__current_state)) 
              | (2U == vlSelf->f1_fsm__DOT__current_state)) 
             | (3U == vlSelf->f1_fsm__DOT__current_state)) 
            | (4U == vlSelf->f1_fsm__DOT__current_state)) 
           | (5U == vlSelf->f1_fsm__DOT__current_state)) 
          | (6U == vlSelf->f1_fsm__DOT__current_state)) 
         | (7U == vlSelf->f1_fsm__DOT__current_state))) {
        if ((0U == vlSelf->f1_fsm__DOT__current_state)) {
            vlSelf->f1_fsm__DOT__next_state = 1U;
            vlSelf->f1_fsm__DOT__out = 0U;
        } else if ((1U == vlSelf->f1_fsm__DOT__current_state)) {
            vlSelf->f1_fsm__DOT__next_state = 2U;
            vlSelf->f1_fsm__DOT__out = (1U | (IData)(vlSelf->f1_fsm__DOT__out));
        } else if ((2U == vlSelf->f1_fsm__DOT__current_state)) {
            vlSelf->f1_fsm__DOT__next_state = 3U;
            vlSelf->f1_fsm__DOT__out = (2U | (IData)(vlSelf->f1_fsm__DOT__out));
        } else if ((3U == vlSelf->f1_fsm__DOT__current_state)) {
            vlSelf->f1_fsm__DOT__next_state = 4U;
            vlSelf->f1_fsm__DOT__out = (4U | (IData)(vlSelf->f1_fsm__DOT__out));
        } else if ((4U == vlSelf->f1_fsm__DOT__current_state)) {
            vlSelf->f1_fsm__DOT__next_state = 5U;
            vlSelf->f1_fsm__DOT__out = (8U | (IData)(vlSelf->f1_fsm__DOT__out));
        } else if ((5U == vlSelf->f1_fsm__DOT__current_state)) {
            vlSelf->f1_fsm__DOT__next_state = 6U;
            vlSelf->f1_fsm__DOT__out = (0x10U | (IData)(vlSelf->f1_fsm__DOT__out));
        } else if ((6U == vlSelf->f1_fsm__DOT__current_state)) {
            vlSelf->f1_fsm__DOT__next_state = 7U;
            vlSelf->f1_fsm__DOT__out = (0x20U | (IData)(vlSelf->f1_fsm__DOT__out));
        } else {
            vlSelf->f1_fsm__DOT__next_state = 8U;
            vlSelf->f1_fsm__DOT__out = (0x40U | (IData)(vlSelf->f1_fsm__DOT__out));
        }
    } else {
        vlSelf->f1_fsm__DOT__next_state = 0U;
        vlSelf->f1_fsm__DOT__out = ((8U == vlSelf->f1_fsm__DOT__current_state)
                                     ? (0x80U | (IData)(vlSelf->f1_fsm__DOT__out))
                                     : 0U);
    }
    vlSelf->data_out = vlSelf->f1_fsm__DOT__out;
}

void Vf1_fsm___024root___eval_nba(Vf1_fsm___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vf1_fsm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vf1_fsm___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vf1_fsm___024root___nba_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
}

void Vf1_fsm___024root___eval_triggers__act(Vf1_fsm___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vf1_fsm___024root___dump_triggers__act(Vf1_fsm___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vf1_fsm___024root___dump_triggers__nba(Vf1_fsm___024root* vlSelf);
#endif  // VL_DEBUG

void Vf1_fsm___024root___eval(Vf1_fsm___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vf1_fsm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vf1_fsm___024root___eval\n"); );
    // Init
    VlTriggerVec<1> __VpreTriggered;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        __VnbaContinue = 0U;
        vlSelf->__VnbaTriggered.clear();
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            vlSelf->__VactContinue = 0U;
            Vf1_fsm___024root___eval_triggers__act(vlSelf);
            if (vlSelf->__VactTriggered.any()) {
                vlSelf->__VactContinue = 1U;
                if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                    Vf1_fsm___024root___dump_triggers__act(vlSelf);
#endif
                    VL_FATAL_MT("f1_fsm.sv", 1, "", "Active region did not converge.");
                }
                vlSelf->__VactIterCount = ((IData)(1U) 
                                           + vlSelf->__VactIterCount);
                __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
                vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
                Vf1_fsm___024root___eval_act(vlSelf);
            }
        }
        if (vlSelf->__VnbaTriggered.any()) {
            __VnbaContinue = 1U;
            if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
                Vf1_fsm___024root___dump_triggers__nba(vlSelf);
#endif
                VL_FATAL_MT("f1_fsm.sv", 1, "", "NBA region did not converge.");
            }
            __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
            Vf1_fsm___024root___eval_nba(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
void Vf1_fsm___024root___eval_debug_assertions(Vf1_fsm___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vf1_fsm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vf1_fsm___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
    if (VL_UNLIKELY((vlSelf->en & 0xfeU))) {
        Verilated::overWidthError("en");}
}
#endif  // VL_DEBUG
