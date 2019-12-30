import Vue from "vue";
import Vuex from "vuex";

import instrument from "./modules/instrument";
import sound from "./modules/sound";
import webBluetoothState from "./modules/webBluetoothState";
import WebBluetoothModule from "web-bluetooth-vuex";

Vue.use(Vuex);

export default new Vuex.Store({
  modules: {
    instrument,
    sound,
    webBluetooth: WebBluetoothModule,
    webBluetoothState
  }
});
