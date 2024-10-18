#include "HalfAdder.h"

/**
 * @file HalfAdder.cpp
 * @author Brad Ekstrand
 * @date June 2020
 * @brief Implementation of the HalfAdder class.
 * @details This class implements a half adder circuit using AND, OR, NAND, and XOR gates.
 */

/**
 * Constructor for the HalfAdder class.
 * @details This constructor initializes a half adder circuit.
 */
HalfAdder::HalfAdder()
{
    and_gate = new AND(1);
    or_gate = new OR(2);
    nand_gate = new NAND(3);
    xor_gate = new AND(4);
}

/**
 * Destructor for the HalfAdder class.
 * @details This destructor releases any memory allocated by the half adder circuit.
 */
HalfAdder::~HalfAdder()
{
    delete and_gate;
    delete or_gate;
    delete nand_gate;
    delete xor_gate;
}

/**
 * Sets the input value for the A input of the half adder circuit.
 * @param val The input value for the A input.
 */
void HalfAdder::set_input_a(const unsigned short int val)
{
    and_gate->set_in1(val);
    or_gate->set_in1(val);
    nand_gate->set_in1(val);
    update();
}

/**
 * Sets the input value for the B input of the half adder circuit.
 * @param val The input value for the B input.
 */
void HalfAdder::set_input_b(const unsigned short int val)
{
    and_gate->set_in2(val);
    or_gate->set_in2(val);
    nand_gate->set_in2(val);
    update();
}

/**
 * Gets the output value of the half adder circuit for the sum.
 * @return The output value of the half adder circuit for the sum.
 */
const unsigned short int HalfAdder::get_sum() const
{
    return xor_gate->out();
}

/**
 * Gets the output value of the half adder circuit for the carry.
 * @return The output value of the half adder circuit for the carry.
 */
const unsigned short int HalfAdder::get_carry() const
{
    return and_gate->out();
}

/**
 * Updates the half adder circuit by propagating the input values through the
 * gates.
 * @details This function is called whenever the input values are changed.
 */
void HalfAdder::update()
{
    // XOR = (A NAND B) AND (A OR B)
    xor_gate->set_in1(nand_gate->out());
    xor_gate->set_in2(or_gate->out());
}