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

Test(and_gate, invalid_pin_throws) {
    nts::AndGate g;
    cr_assert_throw(g.compute(1), nts::NtsException);
    cr_assert_throw(g.compute(2), nts::NtsException);
    cr_assert_throw(g.compute(0), nts::NtsException);
}

Test(and_gate, no_inputs_returns_undefined) {
    nts::AndGate g;
    cr_assert_eq(g.compute(3), nts::Undefined);
}

Test(and_gate, true_and_true_returns_true) {
    nts::AndGate g;
    nts::TrueComp a, b;
    g.setLink(1, a, 1);
    g.setLink(2, b, 1);
    cr_assert_eq(g.compute(3), nts::True);
}

Test(and_gate, true_and_false_returns_false) {
    nts::AndGate g;
    nts::TrueComp a;
    nts::FalseComp b;
    g.setLink(1, a, 1);
    g.setLink(2, b, 1);
    cr_assert_eq(g.compute(3), nts::False);
}

Test(and_gate, false_and_false_returns_false) {
    nts::AndGate g;
    nts::FalseComp a, b;
    g.setLink(1, a, 1);
    g.setLink(2, b, 1);
    cr_assert_eq(g.compute(3), nts::False);
}

Test(and_gate, false_and_undefined_returns_false) {
    nts::AndGate g;
    nts::FalseComp a;
    nts::Input b;
    g.setLink(1, a, 1);
    g.setLink(2, b, 1);
    cr_assert_eq(g.compute(3), nts::False);
}

Test(and_gate, true_and_undefined_returns_undefined) {
    nts::AndGate g;
    nts::TrueComp a;
    nts::Input b;
    g.setLink(1, a, 1);
    g.setLink(2, b, 1);
    cr_assert_eq(g.compute(3), nts::Undefined);
}

Test(and_gate, invalid_setlink_pin_throws) {
    nts::AndGate g;
    nts::TrueComp t;
    cr_assert_throw(g.setLink(99, t, 1), nts::NtsException);
}
