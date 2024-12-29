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
 * @file      driver_aht30.h
 * @brief     driver aht30 header file
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

#ifndef DRIVER_AHT30_H
#define DRIVER_AHT30_H

#include <stdio.h>
#include <stdint.h>
#include <string.h>

#ifdef __cplusplus
extern "C"{
#endif

/**
 * @defgroup aht30_driver aht30 driver function
 * @brief    aht30 driver modules
 * @{
 */

/**
 * @addtogroup aht30_base_driver
 * @{
 */

/**
 * @brief aht30 status enumeration definition
 */
typedef enum
{
    AHT30_STATUS_BUSY               = (1 << 7),        /**< busy bit */
    AHT30_STATUS_NOR_MODE           = (0 << 5),        /**< nor mode */
    AHT30_STATUS_CYC_MODE           = (1 << 5),        /**< cyc mode */
    AHT30_STATUS_CMD_MODE           = (2 << 5),        /**< cmd mode */
    AHT30_STATUS_CRC_FLAG           = (1 << 4),        /**< crc flag */
    AHT30_STATUS_CALIBRATION_ENABLE = (1 << 3),        /**< calibration enable */
    AHT30_STATUS_CMP_INT            = (1 << 2),        /**< comparation interrupt */
} aht30_status_t;

/**
 * @brief aht30 handle structure definition
 */
typedef struct aht30_handle_s
{
    uint8_t (*iic_init)(void);                                                 /**< point to an iic_init function address */
    uint8_t (*iic_deinit)(void);                                               /**< point to an iic_deinit function address */
    uint8_t (*iic_read_cmd)(uint8_t addr, uint8_t *buf, uint16_t len);         /**< point to an iic_read_cmd function address */
    uint8_t (*iic_write_cmd)(uint8_t addr, uint8_t *buf, uint16_t len);        /**< point to an iic_write_cmd function address */
    void (*delay_ms)(uint32_t ms);                                             /**< point to a delay_ms function address */
    void (*debug_print)(const char *const fmt, ...);                           /**< point to a debug_print function address */
    uint8_t inited;                                                            /**< inited flag */
} aht30_handle_t;

/**
 * @brief aht30 information structure definition
 */
typedef struct aht30_info_s
{
    char chip_name[32];                /**< chip name */
    char manufacturer_name[32];        /**< manufacturer name */
    char interface[8];                 /**< chip interface name */
    float supply_voltage_min_v;        /**< chip min supply voltage */
    float supply_voltage_max_v;        /**< chip max supply voltage */
    float max_current_ma;              /**< chip max current */
    float temperature_min;             /**< chip min operating temperature */
    float temperature_max;             /**< chip max operating temperature */
    uint32_t driver_version;           /**< driver version */
} aht30_info_t;

/**
 * @}
 */

/**
 * @defgroup aht30_link_driver aht30 link driver function
 * @brief    aht30 link driver modules
 * @ingroup  aht30_driver
 * @{
 */

/**
 * @brief     initialize aht30_handle_t structure
 * @param[in] HANDLE pointer to an aht30 handle structure
 * @param[in] STRUCTURE aht30_handle_t
 * @note      none
 */
#define DRIVER_AHT30_LINK_INIT(HANDLE, STRUCTURE)      memset(HANDLE, 0, sizeof(STRUCTURE))

/**
 * @brief     link iic_init function
 * @param[in] HANDLE pointer to an aht30 handle structure
 * @param[in] FUC pointer to an iic_init function address
 * @note      none
 */
#define DRIVER_AHT30_LINK_IIC_INIT(HANDLE, FUC)        (HANDLE)->iic_init = FUC

/**
 * @brief     link iic_deinit function
 * @param[in] HANDLE pointer to an aht30 handle structure
 * @param[in] FUC pointer to an iic_deinit function address
 * @note      none
 */
#define DRIVER_AHT30_LINK_IIC_DEINIT(HANDLE, FUC)      (HANDLE)->iic_deinit = FUC

/**
 * @brief     link iic_read_cmd function
 * @param[in] HANDLE pointer to an aht30 handle structure
 * @param[in] FUC pointer to an iic_read_cmd function address
 * @note      none
 */
#define DRIVER_AHT30_LINK_IIC_READ_CMD(HANDLE, FUC)    (HANDLE)->iic_read_cmd = FUC

/**
 * @brief     link iic_write_cmd function
 * @param[in] HANDLE pointer to an aht30 handle structure
 * @param[in] FUC pointer to an iic_write_cmd function address
 * @note      none
 */
#define DRIVER_AHT30_LINK_IIC_WRITE_CMD(HANDLE, FUC)   (HANDLE)->iic_write_cmd = FUC

/**
 * @brief     link delay_ms function
 * @param[in] HANDLE pointer to an aht30 handle structure
 * @param[in] FUC pointer to a delay_ms function address
 * @note      none
 */
#define DRIVER_AHT30_LINK_DELAY_MS(HANDLE, FUC)        (HANDLE)->delay_ms = FUC

/**
 * @brief     link debug_print function
 * @param[in] HANDLE pointer to an aht30 handle structure
 * @param[in] FUC pointer to a debug_print function address
 * @note      none
 */
#define DRIVER_AHT30_LINK_DEBUG_PRINT(HANDLE, FUC)     (HANDLE)->debug_print = FUC

/**
 * @}
 */

/**
 * @defgroup aht30_base_driver aht30 base driver function
 * @brief    aht30 base driver modules
 * @ingroup  aht30_driver
 * @{
 */

/**
 * @brief      get chip's information
 * @param[out] *info pointer to an aht30 info structure
 * @return     status code
 *             - 0 success
 *             - 2 handle is NULL
 * @note       none
 */
uint8_t aht30_info(aht30_info_t *info);

/**
 * @brief     initialize the chip
 * @param[in] *handle pointer to an aht30 handle structure
 * @return    status code
 *            - 0 success
 *            - 1 iic failed
 *            - 2 handle is NULL
 *            - 3 linked functions is NULL
 *            - 4 read status failed
 *            - 5 reset reg failed
 * @note      none
 */
uint8_t aht30_init(aht30_handle_t *handle);

/**
 * @brief     close the chip
 * @param[in] *handle pointer to an aht30 handle structure
 * @return    status code
 *            - 0 success
 *            - 1 deinit failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t aht30_deinit(aht30_handle_t *handle);

/**
 * @brief      read the temperature and humidity data
 * @param[in]  *handle pointer to an aht30 handle structure
 * @param[out] *temperature_raw pointer to a raw temperature buffer
 * @param[out] *temperature_s pointer to a converted temperature buffer
 * @param[out] *humidity_raw pointer to a raw humidity buffer
 * @param[out] *humidity_s pointer to a converted humidity buffer
 * @return     status code
 *             - 0 success
 *             - 1 read temperature humidity failed
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 *             - 4 data is not ready
 *             - 5 crc is error
 * @note       none
 */
uint8_t aht30_read_temperature_humidity(aht30_handle_t *handle, uint32_t *temperature_raw, float *temperature_s,
                                        uint32_t *humidity_raw, uint8_t *humidity_s);

/**
 * @brief      read the temperature
 * @param[in]  *handle pointer to an aht30 handle structure
 * @param[out] *temperature_raw pointer to a raw temperature buffer
 * @param[out] *temperature_s pointer to a converted temperature buffer
 * @return     status code
 *             - 0 success
 *             - 1 read temperature failed
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 *             - 4 data is not ready
 *             - 5 crc is error
 * @note       none
 */
uint8_t aht30_read_temperature(aht30_handle_t *handle, uint32_t *temperature_raw, float *temperature_s);

/**
 * @brief      read the humidity data
 * @param[in]  *handle pointer to an aht30 handle structure
 * @param[out] *humidity_raw pointer to a raw humidity buffer
 * @param[out] *humidity_s pointer to a converted humidity buffer
 * @return     status code
 *             - 0 success
 *             - 1 read humidity failed
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 *             - 4 data is not ready
 *             - 5 crc is error
 * @note       none
 */
uint8_t aht30_read_humidity(aht30_handle_t *handle, uint32_t *humidity_raw, uint8_t *humidity_s);

/**
 * @brief      get status
 * @param[in]  *handle pointer to an aht30 handle structure
 * @param[out] *status pointer to a status buffer
 * @return     status code
 *             - 0 success
 *             - 1 get status failed
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t aht30_get_status(aht30_handle_t *handle, uint8_t *status);

/**
 * @}
 */

/**
 * @defgroup aht30_extend_driver aht30 extend driver function
 * @brief    aht30 extend driver modules
 * @ingroup  aht30_driver
 * @{
 */

/**
 * @brief     set the chip register
 * @param[in] *handle pointer to an aht30 handle structure
 * @param[in] *buf pointer to a data buffer
 * @param[in] len length of data buffer
 * @return    status code
 *            - 0 success
 *            - 1 write failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t aht30_set_reg(aht30_handle_t *handle, uint8_t *buf, uint16_t len);

/**
 * @brief      get the chip register
 * @param[in]  *handle pointer to an aht30 handle structure
 * @param[out] *buf pointer to a data buffer
 * @param[in]  len length of data buffer
 * @return     status code
 *             - 0 success
 *             - 1 read failed
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t aht30_get_reg(aht30_handle_t *handle, uint8_t *buf, uint16_t len);

/**
 * @}
 */

/**
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif
