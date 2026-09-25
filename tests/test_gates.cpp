#include <criterion/criterion.h>
#include "../include/Circuit.hpp"
#include "../include/Factory.hpp"
#include "../include/Exceptions.hpp"

Test(gates, and_gate_true_true) {
    nts::Circuit c;
    auto &f = nts::Factory::getInstance();
    c.addComponent("a", f.createComponent("input"));
    c.addComponent("b", f.createComponent("input"));
    c.addComponent("g", f.createComponent("and"));
    c.addComponent("o", f.createComponent("output"));
    c.link("a", 1, "g", 1);
    c.link("b", 1, "g", 2);
    c.link("g", 3, "o", 1);
    c.setValue("a", "1");
    c.setValue("b", "1");
    c.simulate();
    cr_assert_eq(c.getComponent("o").compute(1), nts::True);
}

Test(gates, and_gate_true_false) {
    nts::Circuit c;
    auto &f = nts::Factory::getInstance();
    c.addComponent("a", f.createComponent("input"));
    c.addComponent("b", f.createComponent("input"));
    c.addComponent("g", f.createComponent("and"));
    c.addComponent("o", f.createComponent("output"));
    c.link("a", 1, "g", 1);
    c.link("b", 1, "g", 2);
    c.link("g", 3, "o", 1);
    c.setValue("a", "1");
    c.setValue("b", "0");
    c.simulate();
    cr_assert_eq(c.getComponent("o").compute(1), nts::False);
}

Test(gates, or_gate_false_false) {
    nts::Circuit c;
    auto &f = nts::Factory::getInstance();
    c.addComponent("a", f.createComponent("input"));
    c.addComponent("b", f.createComponent("input"));
    c.addComponent("g", f.createComponent("or"));
    c.addComponent("o", f.createComponent("output"));
    c.link("a", 1, "g", 1);
    c.link("b", 1, "g", 2);
    c.link("g", 3, "o", 1);
    c.setValue("a", "0");
    c.setValue("b", "0");
    c.simulate();
    cr_assert_eq(c.getComponent("o").compute(1), nts::False);
}

Test(gates, not_gate_inverts) {
    nts::Circuit c;
    auto &f = nts::Factory::getInstance();
    c.addComponent("a", f.createComponent("input"));
    c.addComponent("g", f.createComponent("not"));
    c.addComponent("o", f.createComponent("output"));
    c.link("a", 1, "g", 1);
    c.link("g", 2, "o", 1);
    c.setValue("a", "1");
    c.simulate();
    cr_assert_eq(c.getComponent("o").compute(1), nts::False);
}
