/*
 * acceleration.hpp
 * 
 * 24-05-2025 by madpl
 */
#pragma once

#include <cmath>
#include "defines.hpp"
#include "body.hpp"


vecDouble_t computeAccel(const Body& a, const Body& b);
