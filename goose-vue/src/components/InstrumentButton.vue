<template>
  <div class="button instrumentButton" @click="emitToParent">
    <img class="instrumentIcon" :src="imageLoc" :alt="name + '-icon'" />
  </div>
</template>

<script>
export default {
  name: "InstrumentButton",
  props: ["icon", "name", "active"],
  data() {
    return {
      baseImgLoc: "@/assets/img/"
    };
  },
  computed: {
    imageLoc() {
      let images = require.context("@/assets/img", false, /\.png$/);
      return images("./" + this.icon);
    }
  },
  methods: {
    emitToParent() {
      this.$emit("instrumentChange", this.name);
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
</style>
