#include <criterion/criterion.h>
#include "../include/elementary_comp/AndGate.hpp"
#include "../include/elementary_comp/OrGate.hpp"
#include "../include/elementary_comp/XorGate.hpp"
#include "../include/elementary_comp/NotGate.hpp"
#include "../include/elementary_comp/NandGate.hpp"
#include "../include/elementary_comp/NorGate.hpp"
#include "../include/special_comp/Input.hpp"
#include "../include/special_comp/True.hpp"
#include "../include/special_comp/False.hpp"
#include "../include/Exceptions.hpp"

Test(xor_gate, invalid_pin_throws) {
    nts::XorGate g;
    cr_assert_throw(g.compute(1), nts::NtsException);
    cr_assert_throw(g.compute(0), nts::NtsException);
}

Test(xor_gate, no_inputs_returns_undefined) {
    nts::XorGate g;
    cr_assert_eq(g.compute(3), nts::Undefined);
}

Test(xor_gate, true_xor_false_returns_true) {
    nts::XorGate g;
    nts::TrueComp a;
    nts::FalseComp b;
    g.setLink(1, a, 1);
    g.setLink(2, b, 1);
    cr_assert_eq(g.compute(3), nts::True);
}

Test(xor_gate, true_xor_true_returns_false) {
    nts::XorGate g;
    nts::TrueComp a, b;
    g.setLink(1, a, 1);
    g.setLink(2, b, 1);
    cr_assert_eq(g.compute(3), nts::False);
}

Test(xor_gate, false_xor_false_returns_false) {
    nts::XorGate g;
    nts::FalseComp a, b;
    g.setLink(1, a, 1);
    g.setLink(2, b, 1);
    cr_assert_eq(g.compute(3), nts::False);
}

Test(xor_gate, undefined_xor_anything_returns_undefined) {
    nts::XorGate g;
    nts::Input a;
    nts::TrueComp b;
    g.setLink(1, a, 1);
    g.setLink(2, b, 1);
    cr_assert_eq(g.compute(3), nts::Undefined);
}

Test(xor_gate, invalid_setlink_pin_throws) {
    nts::XorGate g;
    nts::TrueComp t;
    cr_assert_throw(g.setLink(99, t, 1), nts::NtsException);
}
