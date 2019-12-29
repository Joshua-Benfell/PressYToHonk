const state = {
  soundState: true
};

const getters = {};

const actions = {
  toggleSound({ commit }) {
    commit("toggleState");
  }
};

const mutations = {
  toggleState(state) {
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
