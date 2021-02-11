<template>
  <div id="app">
    <BTButton />
    <SoundButton />
    <Y />
    <div
      class="row mx-0 col-12 col-lg-6 offset-lg-3 instrumentTray"
      id="instrumentTray"
    >
      <span
        class="col-4 col-sm-2"
        v-for="instrument in instruments"
        :key="instrument.id"
      >
        <InstrumentButton
          :key="instrument.id"
          :name="instrument.name"
          :icon="instrument.icon"
        />
      </span>
    </div>
  </div>
</template>

<script>
import InstrumentButton from "./components/InstrumentButton";
import Y from "./components/Y";
import SoundButton from "./components/SoundButton";
import BTButton from "./components/BTButton";
import { INSTRUMENTS } from "./constants";

export default {
  name: "app",
  components: {
    InstrumentButton,
    Y,
    SoundButton,
    BTButton
  },
  data() {
    return {};
  },
  mounted() {
    let newInstrument = "honk";
    this.$store.dispatch("instrument/changeInstrument", { newInstrument });
  },
  computed: {
    instruments() {
      return INSTRUMENTS;
    }
  }
};
</script>

<style lang="scss">
#app {
  font-family: Helvetica, Arial, sans-serif;
}

.instrumentTray {
  position: fixed !important;
  bottom: 0;
}

@media (min-width: 992px) {
  #instrumentTray {
    margin-left: 25% !important;
  }
}
</style>
