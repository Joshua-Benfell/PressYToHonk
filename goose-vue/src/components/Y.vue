<template>
  <div class="button yButton" @click="doHonk">
    <img class="yIcon" src="@/assets/img/Y.png" alt="Y" />
  </div>
</template>

<script>
import { mapState } from "vuex";
import { Howl } from "howler";

export default {
  name: "Y",
  data() {
    return {};
  },
  computed: {
    ...mapState({
      instrument: state => state.instrument.instrument,
      currentSound: state => state.instrument.currentCount,
      sound: state => state.sound.soundState
    })
  },
  methods: {
    doHonk() {
      if (!this.sound) {
        return;
      }
      //play honk
      let filePath = require.context("@/assets/sounds", false, /\.wav$/);
      let sound = new Howl({
        src: filePath(
          "./" + this.instrument + "_" + this.currentSound + ".wav"
        )
      });
      sound.play();

      this.$store.dispatch("instrument/changeCurrentCount");
    }
  }
};
</script>

<style lang="scss">
.yButton {
  height: 200px;
  width: 200px;
  position: absolute;
  left: 50%;
  top: 50%;
  transform: translate(-50%, -50%);
  .yIcon {
    max-width: 125px;
    max-height: 125px;
  }
}
</style>
