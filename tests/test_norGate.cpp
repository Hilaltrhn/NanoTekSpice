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

Test(nor_gate, invalid_pin_throws) {
    nts::NorGate g;
    cr_assert_throw(g.compute(1), nts::NtsException);
    cr_assert_throw(g.compute(0), nts::NtsException);
}

Test(nor_gate, false_nor_false_returns_true) {
    nts::NorGate g;
    nts::FalseComp a, b;
    g.setLink(1, a, 1);
    g.setLink(2, b, 1);
    cr_assert_eq(g.compute(3), nts::True);
}

Test(nor_gate, true_nor_false_returns_false) {
    nts::NorGate g;
    nts::TrueComp a;
    nts::FalseComp b;
    g.setLink(1, a, 1);
    g.setLink(2, b, 1);
    cr_assert_eq(g.compute(3), nts::False);
}

Test(nor_gate, true_nor_true_returns_false) {
    nts::NorGate g;
    nts::TrueComp a, b;
    g.setLink(1, a, 1);
    g.setLink(2, b, 1);
    cr_assert_eq(g.compute(3), nts::False);
}

Test(nor_gate, true_nor_undefined_returns_false) {
    nts::NorGate g;
    nts::TrueComp a;
    nts::Input b;
    g.setLink(1, a, 1);
    g.setLink(2, b, 1);
    cr_assert_eq(g.compute(3), nts::False);
}

Test(nor_gate, false_nor_undefined_returns_undefined) {
    nts::NorGate g;
    nts::FalseComp a;
    nts::Input b;
    g.setLink(1, a, 1);
    g.setLink(2, b, 1);
    cr_assert_eq(g.compute(3), nts::Undefined);
}
