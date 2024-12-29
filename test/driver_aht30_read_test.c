/**
 * Copyright (c) 2015 - present LibDriver All rights reserved
 * 
 * The MIT License (MIT)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE. 
 *
 * @file      driver_aht30_read_test.c
 * @brief     driver aht30 read test source file
 * @version   1.0.0
 * @author    Shifeng Li
 * @date      2023-11-30
 *
 * <h3>history</h3>
 * <table>
 * <tr><th>Date        <th>Version  <th>Author      <th>Description
 * <tr><td>2023/11/30  <td>1.0      <td>Shifeng Li  <td>first upload
 * </table>
 */

#include "driver_aht30_read_test.h"

static aht30_handle_t gs_handle;        /**< aht30 handle */

/**
 * @brief     read test
 * @param[in] times test times
 * @return    status code
 *            - 0 success
 *            - 1 read failed
 * @note      none
 */
uint8_t aht30_read_test(uint32_t times)
{
    uint8_t res;
    uint32_t i;
    uint32_t temperature_raw;
    uint32_t humidity_raw;
    float temperature;
    uint8_t humidity;
    aht30_info_t info;
   
    /* link interface function */
    DRIVER_AHT30_LINK_INIT(&gs_handle, aht30_handle_t);
    DRIVER_AHT30_LINK_IIC_INIT(&gs_handle, aht30_interface_iic_init);
    DRIVER_AHT30_LINK_IIC_DEINIT(&gs_handle, aht30_interface_iic_deinit);
    DRIVER_AHT30_LINK_IIC_READ_CMD(&gs_handle, aht30_interface_iic_read_cmd);
    DRIVER_AHT30_LINK_IIC_WRITE_CMD(&gs_handle, aht30_interface_iic_write_cmd);
    DRIVER_AHT30_LINK_DELAY_MS(&gs_handle, aht30_interface_delay_ms);
    DRIVER_AHT30_LINK_DEBUG_PRINT(&gs_handle, aht30_interface_debug_print);

    /* get aht30 information */
    res = aht30_info(&info);
    if (res != 0)
    {
        aht30_interface_debug_print("aht30: get info failed.\n");
       
        return 1;
    }
    else
    {
        /* print aht30 information */
        aht30_interface_debug_print("aht30: chip is %s.\n", info.chip_name);
        aht30_interface_debug_print("aht30: manufacturer is %s.\n", info.manufacturer_name);
        aht30_interface_debug_print("aht30: interface is %s.\n", info.interface);
        aht30_interface_debug_print("aht30: driver version is %d.%d.\n", info.driver_version / 1000, (info.driver_version % 1000) / 100);
        aht30_interface_debug_print("aht30: min supply voltage is %0.1fV.\n", info.supply_voltage_min_v);
        aht30_interface_debug_print("aht30: max supply voltage is %0.1fV.\n", info.supply_voltage_max_v);
        aht30_interface_debug_print("aht30: max current is %0.2fmA.\n", info.max_current_ma);
        aht30_interface_debug_print("aht30: max temperature is %0.1fC.\n", info.temperature_max);
        aht30_interface_debug_print("aht30: min temperature is %0.1fC.\n", info.temperature_min);
    }
    
    /* start basic read test */
    aht30_interface_debug_print("aht30: start read test.\n");
    
    /* aht30 init */
    res = aht30_init(&gs_handle);
    if (res != 0)
    {
        aht30_interface_debug_print("aht30: init failed.\n");
       
        return 1;
    }
    
    /* delay 2000 ms for read */
    aht30_interface_delay_ms(2000);
    for (i = 0; i < times; i++)
    {
        /* read temperature and humidity */
        res = aht30_read_temperature_humidity(&gs_handle, (uint32_t *)&temperature_raw, (float *)&temperature, (uint32_t *)&humidity_raw, (uint8_t *)&humidity);
        if (res != 0)
        {
            aht30_interface_debug_print("aht30: read failed.\n");
            (void)aht30_deinit(&gs_handle);
           
            return 1;
        }
    
        /* print result */
        aht30_interface_debug_print("aht30: temperature: %.01fC.\n", temperature);
        aht30_interface_debug_print("aht30: humidity: %d%%.\n", humidity);

        /* delay 2000 ms*/
        aht30_interface_delay_ms(2000);
    }

    /* finish basic read test and exit */
    aht30_interface_debug_print("aht30: finish read test.\n");
    (void)aht30_deinit(&gs_handle);
    
    return 0;
}
