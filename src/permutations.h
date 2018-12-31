#pragma once
#include <string>

/*!
 * A collection of functions related to mathematical permutations.
 * 
 */
class permutations
{
public:
    /*!
     * Initializes a new instance of the permutations class.
     * 
     */
    permutations();

    /*!
     * Finalizes an instance of the permutations class.
     * 
     */
    ~permutations();

    /*!
     * Multiplies and simplifies a collection of cycles.
     * 
     * \param formula The formula to simplify.
     * \return The simplified cycle.
     */
    static std::string multiply_cycle(std::string formula);
};
