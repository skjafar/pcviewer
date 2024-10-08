#ifndef DATA_H
#define DATA_H

#define VERSION "1.0"                 // First official release
#define CONTROLLER_PERIOD 0.5       //the rate at which the controller runs on the controller card in ms
#define STANDBY_CURRENT 5           //the standby default current
#define REGISTERS_FILE "resources/registers.map"
#define BLOCKS_FILE "resources/blocks.map"
#define FAULTS_FILE "resources/faults.map"
#define DEVICES_FILE "resources/devices.map"
#define PARAMETERS_FILE "resources/parameters.map"

#define GLOBAL_STATE_MACHINE_REGISTER_NAME "STATE_HANDLER"
#define SEQUENCER_STATE_MACHINE_REGISTER_NAME "STATE_SEQUENCER"

#define COMMAND_REGISTER_NAME "COMMAND"
#define SYSTEM_PRIORITY_REGISTER_NAME "SYSTEM_PRIORITY"

#define DATA_TRANSFER_INIT_REGISTER_NAME "DATA_TRANSFER_INIT"
#define DATA_BLOCK_DESTINATION_REGISTER_NAME "DATA_BLOCK_DESTINATION"
#define DEVICE_OPERATING_STATE_REGISTER_NAME "DEVICE_OPERATING_STATE"
#define SYSTEM_OPERATING_STATE_REGISTER_NAME "SYSTEM_OPERATION_STATE"
#define RELOAD_PROGRAM_REGISTER_NAME "RELOAD_PROGRAM"

#define WAVEFORM_0_BLOCK_NAME "Waveform 0"
#define WAVEFORM_0_SIZE_REGISTER_NAME "WAVEFORM_0_SIZE"
#define WAVEFORM_0_FINAL_REGISTER_NAME "WAVEFORM_0_FINAL"
#define WAVEFORM_0_PERIOD_REGISTER_NAME "WAVEFORM_0_PERIOD"
#define WAVEFORM_0_TOP_REGISTER_NAME "WAVEFORM_0_TOP"
#define WAVEFORM_1_BLOCK_NAME "Waveform 1"
#define WAVEFORM_1_SIZE_REGISTER_NAME "WAVEFORM_1_SIZE"
#define WAVEFORM_1_FINAL_REGISTER_NAME "WAVEFORM_1_FINAL"
#define WAVEFORM_1_PERIOD_REGISTER_NAME "WAVEFORM_1_PERIOD"
#define WAVEFORM_1_TOP_REGISTER_NAME "WAVEFORM_1_TOP"
#define WAVEFORM_2_BLOCK_NAME "Waveform 2"
#define WAVEFORM_2_SIZE_REGISTER_NAME "WAVEFORM_2_SIZE"
#define WAVEFORM_2_FINAL_REGISTER_NAME "WAVEFORM_2_FINAL"
#define WAVEFORM_2_PERIOD_REGISTER_NAME "WAVEFORM_2_PERIOD"
#define WAVEFORM_2_TOP_REGISTER_NAME "WAVEFORM_2_TOP"
#define WAVEFORM_3_BLOCK_NAME "Waveform 3"
#define WAVEFORM_3_SIZE_REGISTER_NAME "WAVEFORM_3_SIZE"
#define WAVEFORM_3_FINAL_REGISTER_NAME "WAVEFORM_3_FINAL"
#define WAVEFORM_3_PERIOD_REGISTER_NAME "WAVEFORM_3_PERIOD"
#define WAVEFORM_3_TOP_REGISTER_NAME "WAVEFORM_3_TOP"

#define WAVEFORM_NEXT_REGISTER_NAME "WAVEFORM_NEXT"

#define REFERENCE_REGISTER_NAME "REFERENCE"

#define PARAMETER_SET_1_BLOCK_NAME "Parameter Set 1"
#define DSP_FIRMWARE_BLOCK_NAME "DSP Firmware"

#define DPC_CC_ID_REGISTER_NAME "DPC_CC_ID"  //Sofian
#define FAULTS_REGISTER_NAME "FAULTS"       //Sofian
#define WARNINGS_REGISTER_NAME "WARNINGS"   //Sofian

#define ILOAD_REGISTER_NAME "ILOAD" //Sofian

#define RAM_BLOCK_NAME "RAM"
#define LOG_INDEX_REGISTER_NAME "LOG_INDEX"
#define LOGGER_STATE_REGISTER_NAME "STATE_LOGGER"

#define STARTUP_DISORDERS_REGISTER_NAME "STARTUP_DISORDERS"
#define RUNTIME_DISORDERS_REGISTER_NAME "RUNTIME_DISORDERS"
#define SHUTDOWN_DISORDERS_REGISTER_NAME "SHUTDOWN_DISORDERS"
#define DISORDERS_REGISTER_NAME "DISORDERS"

//#define WAVEFORM_WORDS_LENGTH 16384
//#define DATALOGGER_CHANNEL_WORDS_LENGTH 8192
//#define PARAMETER_SETS_NUMBER 4

#define COPY_BUFFER_WORDS 262144
#define FLASH_SECTOR_WORDS 32768

#define LOGGER_SAMPLES 4096
#define SAMPLES_PER_SECOND 100

#define DEFAULT_CONTROLLER_PORT 9322
#define CONNECT_AUTOMATICALLY true
#define SEARCH_AUTOMATICALLY true
#define DPC_CC_ID_REGISTER 0x40CC // DPC_CC_ID Register
#define DEFAULT_POLL_INTERVAL 1000

#define ETHERNET_PRIORITIZED 2
#define RS232_PRIORITIZED 4

#define ENABLE_MULTI_ACCESS_RAM_WORKAROUND

enum command_t
{
	COMMAND_OFF					,
	COMMAND_STANDBY				,
	COMMAND_ON					,
	COMMAND_FAULT				,
	COMMAND_RESET				,
	COMMAND_OPENLOOP			,
	COMMAND_SEMIAUTO			,
	COMMAND_AUTO				,
	COMMAND_MANUAL				,
	COMMAND_STOP				,
	COMMAND_PAUSE				,
	COMMAND_RESUME				,
	COMMAND_TRIGGER				,
	COMMAND_START_LOG			,
	COMMAND_STOP_LOG			,
	COMMAND_NEXT				,
	COMMAND_SYNC				,
	COMMAND_START_SYNC			,
	COMMAND_STOP_SYNC			,
	COMMAND_START_CAPTURE		,
	COMMAND_STOP_CAPTURE		,
};

enum global_state_t : uint32_t
{
	GLOBAL_STATE_OFF				,
	GLOBAL_STATE_STANDBY			,
	GLOBAL_STATE_ON					,
	GLOBAL_STATE_FAULT				,
	GLOBAL_STATE_OPENLOOP			,
	GLOBAL_STATE_REPLY				,
    GLOBAL_STATE_INVALID			,
};

enum sequencer_state_t
{
    SEQ_STATE_IDLE				,
	SEQ_STATE_DC				,
    SEQ_STATE_ARMED				,
	SEQ_STATE_SEMIAUTO			,
	SEQ_STATE_SEMIAUTO_ACTIVE	,
    SEQ_STATE_AUTO				,
    SEQ_STATE_AUTO_ACTIVE		,
    SEQ_STATE_MANUAL			,
    SEQ_STATE_MANUAL_ACTIVE		,
};

enum device_state_t
{
    DEVICE_STATE_MONITOR = 0x0,
    DEVICE_STATE_OFF = 0x1,
    DEVICE_STATE_ON = 0x2,
    DEVICE_STATE_ADC_CAL = 0x3,
    DEVICE_STATE_LOCKED = 0x4,
    DEVICE_STATE_TRANSIENT = 0x5,
    DEVICE_STATE_OFF_LOCKED = 0x6,
    DEVICE_STATE_DOWNLOAD_DATA = 0x8,
    DEVICE_STATE_SAVE_DATA = 0x9,
    DEVICE_STATE_MODIFY_DATA = 0xb,
    DEVICE_STATE_ON_DISABLED = 0x101,
    DEVICE_STATE_ON_KICK = 0x102,
    DEVICE_STATE_ON_TOP = 0x103,
    DEVICE_STATE_ON_DOWN = 0x104,
    DEVICE_STATE_ON_RECOVERY = 0x105,
    DEVICE_STATE_ON_BAD_LOAD = 0x106,
};

enum logger_state_t
{
    LOGGER_STATE_IDLE,
    LOGGER_STATE_ACTIVE,
    LOGGER_STATE_POSTMORTEM,
    LOGGER_STATE_INTERLOCK,
};

enum mode
{
	MODE_DC	=	0,
	MODE_WAVEFORM
};

#endif // DATA_H
