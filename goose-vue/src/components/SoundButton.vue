<template>
  <button
    class="button smallButton"
    @click="toggleSound"
    @mouseup="mouseup"
    ref="button"
  >
    <img class="smallIcon" :src="imageLoc" alt="soundIcon" />
  </button>
</template>

<script>
import { mapState } from "vuex";

export default {
  name: "SoundButton",
  data() {
    return {};
  },
  computed: {
    ...mapState({
      sound: state => state.sound.soundState
    }),
    imageLoc() {
      let imageName = this.sound ? "soundOn.png" : "soundOff.png";
      let images = require.context("@/assets/img", false, /\.png$/);
      return images("./" + imageName);
    }
  },
  methods: {
    toggleSound() {
      this.$store.dispatch("toggleSound");
    },
    mouseup() {
      this.$refs.button.blur();
    }
  }
};
</script>

<style lang="scss"></style>
