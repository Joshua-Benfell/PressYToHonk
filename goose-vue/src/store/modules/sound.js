import { TOGGLE_SOUND } from "@/constants";

const state = {
  soundState: true
};

const getters = {};

const actions = {
  toggleSound({ commit }) {
    commit(TOGGLE_SOUND);
  }
};

const mutations = {
  [TOGGLE_SOUND](state) {
    state.soundState = !state.soundState;
  }
};

export default {
  namespace: true,
  state,
  getters,
  actions,
  mutations
};
