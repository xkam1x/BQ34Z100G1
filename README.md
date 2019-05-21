
# BQ34Z100G1

Library to configure and use TI BQ34Z100G1 fuel gauge with Arduino platform.

Steps to follow for new pack.

1. Update design capacity.
2. Update Q max.
3. Update design energy.
4. Update cell charge voltage range.
5. Update number of series cells.
6. Update pack configuration.
7. Update charge termination parameters.
8. Calibrate cc offset. (No current applied)
9. Calibrate board offset. (No currrent applied)
10. Calibrate voltage divider. (Apply known voltage and use that)
11. Calibrate sense resistor. (Apply known current, current from battery is negetive)
12. Set current deadband if current is non zero without load.
13. Set ready and start learning cycle.

