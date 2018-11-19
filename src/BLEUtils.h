/*
 * BLEUtils.h
 *
 *  Created on: Mar 25, 2017
 *      Author: kolban
 */

#ifndef COMPONENTS_CPP_UTILS_BLEUTILS_H_
#define COMPONENTS_CPP_UTILS_BLEUTILS_H_
#include "sdkconfig.h"
#if defined(CONFIG_BT_ENABLED)
#include <esp_gattc_api.h>   // ESP32 BLE
#include <esp_gatts_api.h>   // ESP32 BLE
#include <esp_gap_ble_api.h> // ESP32 BLE
#include <string>
#include "BLEClient.h"

/**
 * @brief A set of general %BLE utilities.
 */
class BLEUtils {
public:
	static const char*        addressTypeToString(esp_ble_addr_type_t type);
	static std::string        adFlagsToString(uint8_t adFlags);
	static const char*        advTypeToString(uint8_t advType);
	static char*              buildHexData(uint8_t* target, uint8_t* source, uint8_t length);
	static std::string        buildPrintData(uint8_t* source, size_t length);
	static std::string        characteristicPropertiesToString(esp_gatt_char_prop_t prop);
	static const char*        devTypeToString(esp_bt_dev_type_t type);
	static esp_gatt_id_t	  buildGattId(esp_bt_uuid_t uuid, uint8_t inst_id = 0);
	static esp_gatt_srvc_id_t buildGattSrvcId(esp_gatt_id_t gattId, bool is_primary = true);
	static void dumpGapEvent(
		esp_gap_ble_cb_event_t  event,
		esp_ble_gap_cb_param_t* param);
	static void dumpGattClientEvent(
		esp_gattc_cb_event_t      event,
		esp_gatt_if_t             gattc_if,
		esp_ble_gattc_cb_param_t* evtParam);
	static void dumpGattServerEvent(
		esp_gatts_cb_event_t      event,
		esp_gatt_if_t             gatts_if,
		esp_ble_gatts_cb_param_t* evtParam);
	static const char* eventTypeToString(esp_ble_evt_type_t eventType);
	static BLEClient*  findByAddress(BLEAddress address);
	static BLEClient*  findByConnId(uint16_t conn_id);
	static const char* gapEventToString(uint32_t eventType);
	static std::string gattCharacteristicUUIDToString(uint32_t characteristicUUID);
	static std::string gattClientEventTypeToString(esp_gattc_cb_event_t eventType);
	static std::string gattCloseReasonToString(esp_gatt_conn_reason_t reason);
	static std::string gattcServiceElementToString(esp_gattc_service_elem_t* pGATTCServiceElement);
	static std::string gattDescriptorUUIDToString(uint32_t descriptorUUID);
	static std::string gattServerEventTypeToString(esp_gatts_cb_event_t eventType);
	static std::string gattServiceIdToString(esp_gatt_srvc_id_t srvcId);
	static std::string gattServiceToString(uint32_t serviceId);
	static std::string gattStatusToString(esp_gatt_status_t status);
	static std::string getMember(uint32_t memberId);
	static void        registerByAddress(BLEAddress address, BLEClient* pDevice);
	static void        registerByConnId(uint16_t conn_id, BLEClient* pDevice);
	static const char* searchEventTypeToString(esp_gap_search_evt_t searchEvt);
};

#endif // CONFIG_BT_ENABLED
#endif /* COMPONENTS_CPP_UTILS_BLEUTILS_H_ */