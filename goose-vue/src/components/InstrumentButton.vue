<template>
  <button
    class="button smallButton instrumentButton"
    :class="currentInstrumentName == name ? 'currentInstrument' : ''"
    @click="changeInstrument"
    @mouseup="mouseup"
    ref="button"
  >
    <img class="smallIcon" :src="imageLoc" :alt="name + '-icon'" />
  </button>
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
    },
    currentInstrumentName() {
      if (this.currentInstrument) {
        return this.currentInstrument.name;
      }
      return "honk";
    }
  },
  methods: {
    changeInstrument() {
      let newInstrument = this.name;
      this.$store.dispatch("instrument/changeInstrument", { newInstrument });
    },
    mouseup() {
      this.$refs.button.blur();
    }
  }
};
</script>

<style lang="scss"></style>
