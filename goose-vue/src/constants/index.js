// Instrument Constant Data
export const INSTRUMENTS = {
  honk: {
    id: 0,
    name: "honk",
    icon: "honk.png",
    maxCount: 5
  },
  glass: {
    id: 1,
    name: "glass",
    icon: "glass.png",
    maxCount: 4
  },
  harmonica: {
    id: 2,
    name: "harmonica",
    icon: "harmonica.png",
    maxCount: 6
  },
  soap: {
    id: 3,
    name: "soap",
    icon: "soap.png",
    maxCount: 4
  },
  trashlid: {
    id: 4,
    name: "trashlid",
    icon: "trashlid.png",
    maxCount: 5
  },
  walkie_talkie: {
    id: 5,
    name: "walkie_talkie",
    icon: "walkie_talkie.png",
    maxCount: 3
  }
};

// Instrument Store Module Constants
export const SET_INSTRUMENT = "setInstrument";
export const SET_MAX_COUNT = "setMaxCount";
export const SET_CURRENT_COUNT = "setCurrentCount";
export const INCREMENT = "incrementCurrentCount";

// sound Constants
export const TOGGLE_SOUND = "toggleState";

// webBluetoothState Constants
export const SET_DEVICE_ID = "setDeviceID";
export const SERVICE_UUID = "4fafc201-1fb5-459e-8fcc-c5c9c331914b";
export const CHARACTERISTIC_UUID = "beb5483e-36e1-4688-b7f5-ea07361b26a8";
