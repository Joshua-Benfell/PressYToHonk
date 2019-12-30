import { SET_DEVICE_ID, SERVICE_UUID, CHARACTERISTIC_UUID } from "@/constants";

const state = {
  deviceID: "",
  serviceUUID: SERVICE_UUID,
  characteristicUUID: CHARACTERISTIC_UUID
};

const getters = {};

const actions = {
  setDeviceID({ commit }, { deviceID }) {
    commit(SET_DEVICE_ID, deviceID);
  }
};

const mutations = {
  [SET_DEVICE_ID](state, result) {
    state.deviceID = result;
  }
};

export default {
  namespaced: true,
  state,
  getters,
  actions,
  mutations
};
