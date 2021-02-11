import {
  INSTRUMENTS,
  SET_INSTRUMENT,
  SET_MAX_COUNT,
  SET_CURRENT_COUNT,
  INCREMENT
} from "@/constants";

const state = {
  instrument: null,
  maxCount: 5,
  currentCount: 0
};

const getters = {};

const actions = {
  changeInstrument({ commit }, { newInstrument }) {
    if (newInstrument in INSTRUMENTS) {
      let id = INSTRUMENTS[newInstrument].id;
      commit(SET_INSTRUMENT, { id, name: newInstrument });
      commit(SET_MAX_COUNT, INSTRUMENTS[newInstrument]["maxCount"]);
      commit(SET_CURRENT_COUNT, 0);
    }
  },
  changeCurrentCount({ commit }) {
    commit(INCREMENT);
  }
};

const mutations = {
  [SET_INSTRUMENT](state, result) {
    state.instrument = result;
  },
  [SET_MAX_COUNT](state, result) {
    state.maxCount = result;
  },
  [SET_CURRENT_COUNT](state, result) {
    state.currentCount = result;
  },
  [INCREMENT](state) {
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
