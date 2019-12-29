<template>
  <div class="button instrumentButton" :class="(currentInstrument == name) ? 'currentInstrument' : ''" @click="changeInstrument">
    <img class="instrumentIcon" :src="imageLoc" :alt="name + '-icon'" />
  </div>
</template>

<script>

import { mapState } from "vuex";

export default {
  name: "InstrumentButton",
  props: ["icon", "name"],
  computed: {
    ...mapState({
      currentInstrument: state => state.instrument.instrument
    }),
    imageLoc() {
      let images = require.context("@/assets/img", false, /\.png$/);
      return images("./" + this.icon);
    }
  },
  methods: {
    changeInstrument() {
      let newInstrument = this.name
      this.$store.dispatch("instrument/changeInstrument", { newInstrument });
    }
  }
};
</script>

<style lang="scss">
.instrumentButton {
  width: 75px;
  height: 75px;
  margin: 10px auto;

  .instrumentIcon {
    max-width: 50px;
    max-height: 50px;
  }
}

.currentInstrument {
  background-color: $activeGreen !important;
}
</style>
