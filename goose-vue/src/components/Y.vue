<template>
  <div class="button yButton" @click="$emit('honk')">
    <img class="yIcon" src="@/assets/img/Y.png" alt="Y" />
  </div>
</template>

<script>
export default {
  name: "Y",
  data() {
    return {};
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
