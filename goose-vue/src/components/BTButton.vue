<template>
  <div class="button smallButton float-left ml-2 ml-lg-5" @click="toggleBTConnection">
    <img class="smallIcon" src="@/assets/img/bluetoothOff.png" alt="bluetoothIcon" />
  </div>
</template>

<script>
import { mapState } from "vuex";

export default {
  name: "BTButton",
  data() {
    return {
      options: {
        namePrefix: "Honk"
      }
    };
  },
  computed: {
    ...mapState({
      sound: state => state.sound.soundState
    }),
    imageLoc() {
      let imageName = (this.sound) ? "soundOn.png" : "soundOff.png";
      let images = require.context("@/assets/img", false, /\.png$/);
      return images("./" + imageName);
    }
  },
  methods: {
    toggleBTConnection() {
      this.connect();
    },
    connect() {
      
    },
    disconnect() {

    }
  }
};
</script>

<style lang="scss">
</style>
