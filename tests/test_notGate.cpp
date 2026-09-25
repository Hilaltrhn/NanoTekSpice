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

Test(not_gate, invalid_pin_throws) {
    nts::NotGate g;
    cr_assert_throw(g.compute(1), nts::NtsException);
    cr_assert_throw(g.compute(0), nts::NtsException);
}

Test(not_gate, no_input_returns_undefined) {
    nts::NotGate g;
    cr_assert_eq(g.compute(2), nts::Undefined);
}

Test(not_gate, not_true_returns_false) {
    nts::NotGate g;
    nts::TrueComp t;
    g.setLink(1, t, 1);
    cr_assert_eq(g.compute(2), nts::False);
}

Test(not_gate, not_false_returns_true) {
    nts::NotGate g;
    nts::FalseComp f;
    g.setLink(1, f, 1);
    cr_assert_eq(g.compute(2), nts::True);
}

Test(not_gate, not_undefined_returns_undefined) {
    nts::NotGate g;
    nts::Input i;
    g.setLink(1, i, 1);
    cr_assert_eq(g.compute(2), nts::Undefined);
}

Test(not_gate, invalid_setlink_pin_throws) {
    nts::NotGate g;
    nts::TrueComp t;
    cr_assert_throw(g.setLink(99, t, 1), nts::NtsException);
}
