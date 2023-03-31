/*
=====================================================
assert replacement
=====================================================
*/

#include <vector>

void process_data(std::vector<int>& numbers)
{
    // contract_assert is a true keyword. It handles commas and templates flawlessly!
    contract_assert(!numbers.empty()); 

    int primary_value = numbers[0];

    // Verifying an internal invariant before moving on
    contract_assert(primary_value > 0);
}

/*
=====================================================
pre: Defines preconditions (checked on function entry).

post: Defines postconditions (checked on function exit).

contract_assert: Defines internal assertions (checked exactly where it is placed in the function body).
=====================================================
*/

double divide(double numerator, double denominator)
    pre(denominator != 0.0)             // Precondition contract
    post(r: r == (numerator / denominator)) // Postcondition contract (r maps to return value)
{
    double result = numerator / denominator;
    
    // Internal contract assertion
    contract_assert(result == result); // Quick check that result is not NaN
    
    return result;
}

/*
=====================================================
std::contract_violation

When contract_assert fails, it triggers a global function called handle_contract_violation.
It can be overrided using custom logging.
=====================================================
*/

// You can define this globally in your application to catch contract failures
void handle_contract_violation(const std::contract_violation& violation)
{
    std::cerr << "Contract failed in file: " << violation.location().file_name()
              << " on line: " << violation.location().line() << "\n"
              << "Condition: " << violation.predicate_text() << "\n";
}