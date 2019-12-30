<template>
  <div class="button smallButton float-right mr-2 mr-lg-5" @click="toggleSound">
    <img class="smallIcon" :src="imageLoc" alt="soundIcon" />
  </div>
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
    }
  }
};
</script>

<style lang="scss"></style>
