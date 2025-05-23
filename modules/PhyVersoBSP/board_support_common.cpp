// SPDX-License-Identifier: Apache-2.0
// Copyright Pionix GmbH and Contributors to EVerest

#include "board_support_common.hpp"

namespace module {

types::board_support_common::BspEvent to_bsp_event(CpState s) {
    switch (s) {
    case CpState_STATE_A:
        return {types::board_support_common::Event::A};
    case CpState_STATE_B:
        return {types::board_support_common::Event::B};
    case CpState_STATE_C:
        return {types::board_support_common::Event::C};
    case CpState_STATE_D:
        return {types::board_support_common::Event::D};
    case CpState_STATE_E:
        return {types::board_support_common::Event::E};
    case CpState_STATE_F:
        return {types::board_support_common::Event::F};
    // This should never happen
    default:
        return {types::board_support_common::Event::F};
    }
}

types::board_support_common::BspEvent to_bsp_event(CoilState s) {
    // TODO: implement coil type handling
    if (s.coil_state) {
        return {types::board_support_common::Event::PowerOn};
    } else {
        return {types::board_support_common::Event::PowerOff};
    }
}

types::board_support_common::ProximityPilot to_pp_ampacity(PpState s) {
    switch (s) {
    case PpState_STATE_NC: {
        return {types::board_support_common::Ampacity::None};
    }
    case PpState_STATE_13A: {
        return {types::board_support_common::Ampacity::A_13};
    }
    case PpState_STATE_20A: {
        return {types::board_support_common::Ampacity::A_20};
    }
    case PpState_STATE_32A: {
        return {types::board_support_common::Ampacity::A_32};
    }
    case PpState_STATE_70A: {
        return {types::board_support_common::Ampacity::A_63_3ph_70_1ph};
    }
    default: {
        return {types::board_support_common::Ampacity::None};
    }
    }
}

} // namespace module
