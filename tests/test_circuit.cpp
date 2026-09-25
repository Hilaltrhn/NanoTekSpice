#include <criterion/criterion.h>
#include "../include/Circuit.hpp"
#include "../include/Factory.hpp"
#include "../include/Exceptions.hpp"

Test(circuit, initial_tick_is_zero) {
    nts::Circuit c;
    cr_assert_eq(c.getTick(), 0);
}

Test(circuit, add_and_get_component) {
    nts::Circuit c;
    auto &f = nts::Factory::getInstance();
    c.addComponent("in1", f.createComponent("input"));
    cr_assert(c.hasComponent("in1"));
}

Test(circuit, get_unknown_component_throws) {
    nts::Circuit c;
    cr_assert_throw(c.getComponent("nope"), nts::CircuitExeption);
}

Test(circuit, simulate_increments_tick) {
    nts::Circuit c;
    auto &f = nts::Factory::getInstance();
    c.addComponent("in1", f.createComponent("input"));
    c.addComponent("out1", f.createComponent("output"));
    c.link("in1", 1, "out1", 1);
    c.simulate();
    cr_assert_eq(c.getTick(), 1);
}

Test(circuit, set_value_invalid_throws) {
    nts::Circuit c;
    auto &f = nts::Factory::getInstance();
    c.addComponent("in1", f.createComponent("input"));
    cr_assert_throw(c.setValue("in1", "invalid"), nts::NtsException);
}
