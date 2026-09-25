#include <criterion/criterion.h>
#include "../include/Circuit.hpp"
#include "../include/Factory.hpp"
#include "../include/Exceptions.hpp"

Test(factory, singleton_same_instance) {
    cr_assert_eq(&nts::Factory::getInstance(), &nts::Factory::getInstance());
}

Test(factory, create_known_components) {
    auto &f = nts::Factory::getInstance();
    cr_assert_not_null(f.createComponent("and").get());
    cr_assert_not_null(f.createComponent("or").get());
    cr_assert_not_null(f.createComponent("xor").get());
    cr_assert_not_null(f.createComponent("not").get());
    cr_assert_not_null(f.createComponent("input").get());
    cr_assert_not_null(f.createComponent("output").get());
    cr_assert_not_null(f.createComponent("clock").get());
}

Test(factory, create_unknown_throws) {
    cr_assert_throw(
        nts::Factory::getInstance().createComponent("doesnotexist"),
        nts::FactoryException
    );
}
