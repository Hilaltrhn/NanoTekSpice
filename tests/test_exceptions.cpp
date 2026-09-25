#include <criterion/criterion.h>
#include "../include/Circuit.hpp"
#include "../include/Factory.hpp"
#include "../include/Exceptions.hpp"

Test(exceptions, nts_exception_message) {
    nts::NtsException e("test error");
    cr_assert_str_eq(e.what(), "test error");
}
