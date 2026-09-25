#include <criterion/criterion.h>
#include "../include/special_comp/Clock.hpp"
#include "../include/special_comp/Input.hpp"
#include "../include/special_comp/Output.hpp"
#include "../include/special_comp/True.hpp"
#include "../include/special_comp/False.hpp"
#include "../include/Exceptions.hpp"

Test(output, no_link_returns_undefined) {
    nts::Output o;
    cr_assert_eq(o.compute(1), nts::Undefined);
}

Test(output, invalid_pin_throws) {
    nts::Output o;
    cr_assert_throw(o.compute(0), nts::NtsException);
    cr_assert_throw(o.compute(2), nts::NtsException);
}

Test(output, reads_linked_input_true) {
    nts::Input i;
    nts::Output o;
    i.setValue(nts::True);
    o.setLink(1, i, 1);
    cr_assert_eq(o.compute(1), nts::True);
}

Test(output, reads_linked_input_false) {
    nts::Input i;
    nts::Output o;
    i.setValue(nts::False);
    o.setLink(1, i, 1);
    cr_assert_eq(o.compute(1), nts::False);
}

Test(output, reflects_input_value_change) {
    nts::Input i;
    nts::Output o;
    o.setLink(1, i, 1);
    i.setValue(nts::True);
    cr_assert_eq(o.compute(1), nts::True);
    i.setValue(nts::False);
    cr_assert_eq(o.compute(1), nts::False);
}

Test(output, reads_linked_true_comp) {
    nts::TrueComp t;
    nts::Output o;
    o.setLink(1, t, 1);
    cr_assert_eq(o.compute(1), nts::True);
}

Test(output, reads_linked_false_comp) {
    nts::FalseComp f;
    nts::Output o;
    o.setLink(1, f, 1);
    cr_assert_eq(o.compute(1), nts::False);
}
