#include <criterion/criterion.h>
#include "../include/special_comp/Clock.hpp"
#include "../include/special_comp/Input.hpp"
#include "../include/special_comp/Output.hpp"
#include "../include/special_comp/True.hpp"
#include "../include/special_comp/False.hpp"
#include "../include/Exceptions.hpp"

Test(true_comp, always_returns_true) {
    nts::TrueComp t;
    cr_assert_eq(t.compute(1), nts::True);
    cr_assert_eq(t.compute(0), nts::True);
    cr_assert_eq(t.compute(99), nts::True);
}

Test(true_comp, simulate_does_not_change_value) {
    nts::TrueComp t;
    t.simulate(1);
    cr_assert_eq(t.compute(1), nts::True);
}
