# CIGARETTE

This is the C++ implementation of the veGAs/veGAs+ algoRithm (CIGAR) for multi-dimensional integral calculations.

The core functionality is derived from the original CIGAR program, see https://github.com/ycwu1030/CIGAR. CIGARETTE extends CIGAR with the key ability to perform binning directly during the Monte Carlo sampling process. This integrated binning mechanism ensures the result produced by CIGARETTE can be used immediately for drawing differential distribution figures, eliminating the need for any additional post-processing.

## Usage and Interfaces
For a comprehensive guide on how to use this program, please refer to the provided example in main.cpp. The set of available interfaces and configuration options can be found in VEGAS.h.

A Python script is also included to facilitate the plotting of the output figures.

## Reference

- G. Peter Lepage; A New Algorithm for Adaptive Multidimensional Integration; Journal of Computational Physics 27 (1978) 192;
- G. Peter Lepage: Adaptive Multidimensional Integration: VEGAS Enhanced; arXiv: 2009.05112;

## License
Copyright (C) <2025>  <Han Zhang>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
