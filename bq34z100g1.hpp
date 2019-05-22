//
//  bq34z100g1.hpp
//  SMC
//
//  Created by Kamran Ahmad on 08/05/2019.
//  Copyright © 2019 xkam1x. All rights reserved.
//

#ifndef bq34z100g1_hpp
#define bq34z100g1_hpp

#include <Arduino.h>
#include <Wire.h>

/*
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
 */

class BQ34Z100G1 {
    uint8_t flash_block_data[32];
    
    uint16_t read_register(uint8_t address, uint8_t length);
    uint16_t read_control(uint8_t address_lsb, uint8_t address_msb);
    void read_flash_block(uint8_t sub_class, uint8_t offset);
    void write_reg(uint8_t address, uint8_t value);
    void write_flash_block(uint8_t sub_class, uint8_t offset);
    
    uint8_t flash_block_checksum();
    
    double xemics_to_double(uint32_t value);
    uint32_t double_to_xemics(double value);
    
    void unsealed();
    void enter_calibration();
    void exit_calibration();
    
public:
    
    bool update_design_capacity(int16_t capacity);
    bool update_q_max(int16_t capacity);
    bool update_design_energy(int16_t energy);
    bool update_cell_charge_voltage_range(uint16_t t1_t2, uint16_t t2_t3, uint16_t t3_t4);
    bool update_number_of_series_cells(uint8_t cells);
    bool update_pack_configuration(uint16_t config);
    bool update_charge_termination_parameters(int16_t taper_current, int16_t min_taper_capacity, int16_t cell_taper_voltage, uint8_t taper_window, int8_t tca_set, int8_t tca_clear, int8_t fc_set, int8_t fc_clear);
    void calibrate_cc_offset();
    void calibrate_board_offset();
    void calibrate_voltage_divider(uint16_t applied_voltage, uint8_t cells_count);
    void calibrate_sense_resistor(int16_t applied_current);
    void set_current_deadband(uint8_t deadband);
    void ready();
    
    uint16_t control_status();
    uint16_t device_type();
    uint16_t fw_version();
    uint16_t hw_version();
    uint16_t reset_data();
    uint16_t prev_macwrite();
    uint16_t chem_id();
    uint16_t board_offset();
    uint16_t cc_offset();
    uint16_t cc_offset_save();
    uint16_t df_version();
    uint16_t set_fullsleep();
    uint16_t static_chem_chksum();
    uint16_t sealed();
    uint16_t it_enable();
    uint16_t cal_enable();
    uint16_t reset();
    uint16_t exit_cal();
    uint16_t enter_cal();
    uint16_t offset_cal();
    
    uint8_t state_of_charge(); // 0 to 100%
    uint8_t state_of_charge_max_error(); // 1 to 100%
    uint16_t remaining_capacity(); // mAh
    uint16_t full_charge_capacity(); // mAh
    uint16_t voltage(); // mV
    int16_t average_current(); // mA
    uint16_t temperature(); // Unit of x10 K
    uint16_t flags();
    uint16_t flags_b();
    int16_t current(); // mA
    
    uint16_t average_time_to_empty(); // Minutes
    uint16_t average_time_to_full(); // Minutes
    int16_t passed_charge(); // mAh
    uint16_t do_d0_time(); // Minutes
    uint16_t available_energy(); // 10 mWh
    uint16_t average_power(); // 10 mW
    uint16_t serial_number();
    uint16_t internal_temperature(); // Unit of x10 K
    uint16_t cycle_count(); // Counts
    uint16_t state_of_health(); // 0 to 100%
    uint16_t charge_voltage(); // mV
    uint16_t charge_current(); // mA
    uint16_t pack_configuration();
    uint16_t design_capacity(); // mAh
    uint8_t grid_number();
    uint8_t learned_status();
    uint16_t dod_at_eoc();
    uint16_t q_start(); // mAh
    uint16_t true_fcc(); // mAh
    uint16_t state_time(); // s
    uint16_t q_max_passed_q(); // mAh
    uint16_t dod_0();
    uint16_t q_max_dod_0();
    uint16_t q_max_time();
};

#endif /* bq34z100g1_hpp */
