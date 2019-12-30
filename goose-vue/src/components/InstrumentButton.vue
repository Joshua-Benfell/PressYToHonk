<template>
  <div
    class="button smallButton"
    :class="currentInstrument == name ? 'currentInstrument' : ''"
    @click="changeInstrument"
  >
    <img class="smallIcon" :src="imageLoc" :alt="name + '-icon'" />
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
      let newInstrument = this.name;
      this.$store.dispatch("instrument/changeInstrument", { newInstrument });
    }
  }
};
</script>

<style lang="scss">
.currentInstrument {
  background-color: $activeGreen !important;
}
</style>
