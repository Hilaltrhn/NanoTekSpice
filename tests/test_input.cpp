#include <criterion/criterion.h>
#include "../include/special_comp/Clock.hpp"
#include "../include/special_comp/Input.hpp"
#include "../include/special_comp/Output.hpp"
#include "../include/special_comp/True.hpp"
#include "../include/special_comp/False.hpp"
#include "../include/Exceptions.hpp"

Test(input, initial_value_is_undefined) {
    nts::Input i;
    cr_assert_eq(i.compute(1), nts::Undefined);
}

Test(input, invalid_pin_throws) {
    nts::Input i;
    cr_assert_throw(i.compute(0), nts::NtsException);
    cr_assert_throw(i.compute(2), nts::NtsException);
}

Test(input, set_true) {
    nts::Input i;
    i.setValue(nts::True);
    cr_assert_eq(i.compute(1), nts::True);
}

Test(input, set_false) {
    nts::Input i;
    i.setValue(nts::False);
    cr_assert_eq(i.compute(1), nts::False);
}

Test(input, simulate_does_not_change_value) {
    nts::Input i;
    i.setValue(nts::True);
    i.simulate(1);
    i.simulate(2);
    cr_assert_eq(i.compute(1), nts::True);
}

Test(input, set_value_multiple_times) {
    nts::Input i;
    i.setValue(nts::True);
    i.setValue(nts::False);
    i.setValue(nts::Undefined);
    cr_assert_eq(i.compute(1), nts::Undefined);
}
