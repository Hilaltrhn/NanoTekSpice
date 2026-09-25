#include <criterion/criterion.h>
#include "../include/special_comp/Clock.hpp"
#include "../include/special_comp/Input.hpp"
#include "../include/special_comp/Output.hpp"
#include "../include/special_comp/True.hpp"
#include "../include/special_comp/False.hpp"
#include "../include/Exceptions.hpp"

Test(false_comp, always_returns_false) {
    nts::FalseComp f;
    cr_assert_eq(f.compute(1), nts::False);
    cr_assert_eq(f.compute(0), nts::False);
    cr_assert_eq(f.compute(99), nts::False);
}

Test(false_comp, simulate_does_not_change_value) {
    nts::FalseComp f;
    f.simulate(1);
    cr_assert_eq(f.compute(1), nts::False);
}