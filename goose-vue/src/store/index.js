import Vue from "vue";
import Vuex from "vuex";

import instrument from "./modules/instrument";
import sound from "./modules/sound";

Vue.use(Vuex);

export default new Vuex.Store({
  modules: {
    instrument,
    sound
  }
});
