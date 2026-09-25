#include <criterion/criterion.h>
#include "../include/special_comp/Clock.hpp"
#include "../include/special_comp/Input.hpp"
#include "../include/special_comp/Output.hpp"
#include "../include/special_comp/True.hpp"
#include "../include/special_comp/False.hpp"
#include "../include/Exceptions.hpp"

Test(clock, initial_value_is_undefined) {
    nts::Clock c;
    cr_assert_eq(c.compute(1), nts::Undefined);
}

Test(clock, invalid_pin_throws) {
    nts::Clock c;
    cr_assert_throw(c.compute(2), nts::NtsException);
    cr_assert_throw(c.compute(0), nts::NtsException);
}

Test(clock, set_true_then_simulate_gives_false) {
    nts::Clock c;
    c.setValue(nts::True);
    c.simulate(1);
    cr_assert_eq(c.compute(1), nts::False);
}

Test(clock, set_false_then_simulate_gives_true) {
    nts::Clock c;
    c.setValue(nts::False);
    c.simulate(1);
    cr_assert_eq(c.compute(1), nts::True);
}

Test(clock, toggles_multiple_times) {
    nts::Clock c;
    c.setValue(nts::True);
    c.simulate(1);
    cr_assert_eq(c.compute(1), nts::False);
    c.simulate(2);
    cr_assert_eq(c.compute(1), nts::True);
    c.simulate(3);
    cr_assert_eq(c.compute(1), nts::False);
}

Test(clock, undefined_does_not_toggle) {
    nts::Clock c;
    c.simulate(1);
    cr_assert_eq(c.compute(1), nts::Undefined);
}

