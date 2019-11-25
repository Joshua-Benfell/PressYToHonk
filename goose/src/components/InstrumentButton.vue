<template>
  <div class="button instrumentButton" @click="emitToParent">
    <img class='instrumentIcon' :src="imageLoc" :alt="name+'-icon'">
  </div>
</template>

<script>
export default {
  name: 'InstrumentButton',
  props: ['icon', 'name', "active"],
  data () {
    return {
      baseImgLoc: "src/assets/img/"
    }
  },
  computed:{
    imageLoc(){
      return this.baseImgLoc.concat(this.icon)
    }
  },
  methods:{
    emitToParent(event){
      this.$emit('instrumentChange', this.name)
    }
  }
}
</script>

<style lang="scss">
  .instrumentButton{
    width: 75px;
    height: 75px;
    margin: 10px auto;

    .instrumentIcon{
      max-width: 50px;
      max-height: 50px;
    }
  }


</style>
