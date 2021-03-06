/* This file was generated by plugin 'Nordic Semiconductor nRF5x v.1.2.2' (BDS version 1.0.2116.0) */

#include "service_if.h"
#include <stdint.h>
#include "nrf_log.h"
#include "ble_read_write_service.h" 

static ble_read_write_service_t    m_read_write_service; 

uint8_t m_read_write_service_read_initial_value_data_arr[1]; 
uint8_t m_read_write_service_write_initial_value_data_arr[1]; 
uint8_t m_read_write_service_wwr_initial_value_data_arr[1]; 
uint8_t m_read_write_service_notify_initial_value_data_arr[1]; 
uint8_t m_read_write_service_indicate_initial_value_data_arr[1]; 


/**@brief Function for handling the Read Write Service events.
 *
 * @details This function will be called for all Read Write Service events which are passed to
 *          the application.
 *
 * @param[in]   p_read_write_service   Read Write Service structure.
 * @param[in]   p_evt   Event received from the Read Write Service.
 */
static void on_read_write_service_evt(ble_read_write_service_t * p_read_write_service, ble_read_write_service_evt_t * p_evt)
{
    switch (p_evt->evt_type)
    { 
        case BLE_READ_WRITE_SERVICE_WRITE_EVT_WRITE:
            NRF_LOG_INFO("[Bluetooth_IF]: READ_WRITE_SERVICE_WRITE evt WRITE. \r\n");
            break; 
        case BLE_READ_WRITE_SERVICE_WWR_EVT_WRITE:
            NRF_LOG_INFO("[Bluetooth_IF]: READ_WRITE_SERVICE_WWR evt WRITE. \r\n");
            break; 
        case BLE_READ_WRITE_SERVICE_NOTIFY_EVT_NOTIFICATION_ENABLED:
            NRF_LOG_INFO("[Bluetooth_IF]: READ_WRITE_SERVICE_NOTIFY evt NOTIFICATION_ENABLED. \r\n");
            break;
        case BLE_READ_WRITE_SERVICE_NOTIFY_EVT_NOTIFICATION_DISABLED:
            NRF_LOG_INFO("[Bluetooth_IF]: READ_WRITE_SERVICE_NOTIFY evt NOTIFICATION_DISABLED. \r\n");
            break;
        case BLE_READ_WRITE_SERVICE_NOTIFY_EVT_CCCD_WRITE:
            NRF_LOG_INFO("[Bluetooth_IF]: READ_WRITE_SERVICE_NOTIFY evt CCCD_WRITE. \r\n");
            break; 
        case BLE_READ_WRITE_SERVICE_INDICATE_EVT_NOTIFICATION_ENABLED:
            NRF_LOG_INFO("[Bluetooth_IF]: READ_WRITE_SERVICE_INDICATE evt NOTIFICATION_ENABLED. \r\n");
            break;
        case BLE_READ_WRITE_SERVICE_INDICATE_EVT_NOTIFICATION_DISABLED:
            NRF_LOG_INFO("[Bluetooth_IF]: READ_WRITE_SERVICE_INDICATE evt NOTIFICATION_DISABLED. \r\n");
            break;
        case BLE_READ_WRITE_SERVICE_INDICATE_EVT_CCCD_WRITE:
            NRF_LOG_INFO("[Bluetooth_IF]: READ_WRITE_SERVICE_INDICATE evt CCCD_WRITE. \r\n");
            {
                ble_read_write_service_notify_t notify;
                uint8_t val[40];
                
                memset(val, 0x82, sizeof(val));
                notify.data.size = 30;
                notify.data.p_data = val;
                ble_read_write_service_notify_send(&m_read_write_service, &notify);
            }
            break; 
        default:
            // No implementation needed.
            break;
    }
}


/**@brief Function for initializing the Services generated by Bluetooth Developer Studio.
 *
 *
 * @return      NRF_SUCCESS on successful initialization of services, otherwise an error code.
 */
uint32_t bluetooth_init(void)
{
    uint32_t    err_code; 
    ble_read_write_service_init_t    read_write_service_init; 
    

    // Initialize Read Write Service.
    memset(&read_write_service_init, 0, sizeof(read_write_service_init));

    read_write_service_init.evt_handler = on_read_write_service_evt; 
    read_write_service_init.ble_read_write_service_read_initial_value.data.size = 1;
    read_write_service_init.ble_read_write_service_read_initial_value.data.p_data = m_read_write_service_read_initial_value_data_arr; 
    read_write_service_init.ble_read_write_service_write_initial_value.data.size = 1;
    read_write_service_init.ble_read_write_service_write_initial_value.data.p_data = m_read_write_service_write_initial_value_data_arr; 
    read_write_service_init.ble_read_write_service_wwr_initial_value.data.size = 1;
    read_write_service_init.ble_read_write_service_wwr_initial_value.data.p_data = m_read_write_service_wwr_initial_value_data_arr; 
    read_write_service_init.ble_read_write_service_notify_initial_value.data.size = 1;
    read_write_service_init.ble_read_write_service_notify_initial_value.data.p_data = m_read_write_service_notify_initial_value_data_arr; 
    read_write_service_init.ble_read_write_service_indicate_initial_value.data.size = 1;
    read_write_service_init.ble_read_write_service_indicate_initial_value.data.p_data = m_read_write_service_indicate_initial_value_data_arr; 

    err_code = ble_read_write_service_init(&m_read_write_service, &read_write_service_init);
    if (err_code != NRF_SUCCESS)
    {
        return err_code;
    } 

    return NRF_SUCCESS;
}

/**@brief Function for handling the Application's BLE Stack events.
 *
 * @details Handles all events from the BLE stack of interest to all Bluetooth Developer Studio generated Services.
 *
 * @param[in]   p_ble_evt  Event received from the BLE stack.
 */
void bluetooth_on_ble_evt(ble_evt_t * p_ble_evt)
{ 
    ble_read_write_service_on_ble_evt(&m_read_write_service, p_ble_evt); 
}
