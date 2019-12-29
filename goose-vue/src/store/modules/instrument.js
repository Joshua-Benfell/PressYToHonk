import { INSTRUMENTS } from "../../constants";

const state = {
  instrument: "honk",
  maxCount: 5,
  currentCount: 0
};

const getters = {};

const actions = {
  changeInstrument({ commit }, { newInstrument }) {
    if (newInstrument in INSTRUMENTS) {
      commit("setInstrument", newInstrument);
      commit("setMaxCount", INSTRUMENTS[newInstrument]["maxCount"]);
      commit("setCurrentCount", 0);
    }
  },
  changeCurrentCount({ commit }) {
    commit("incrementCurrentCount");
  }
};

const mutations = {
  setInstrument(state, result) {
    state.instrument = result;
  },
  setMaxCount(state, result) {
    state.maxCount = result;
  },
  setCurrentCount(state, result) {
    state.currentCount = result;
  },
  incrementCurrentCount(state) {
    if (state.currentCount == state.maxCount - 1) {
      state.currentCount = 0;
    } else {
      state.currentCount++;
    }
  }
};

export default {
  namespaced: true,
  state,
  getters,
  actions,
  mutations
};
