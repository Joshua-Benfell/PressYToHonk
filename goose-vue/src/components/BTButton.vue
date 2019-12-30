<template>
  <div
    class="button smallButton float-left ml-2 ml-lg-5"
    :class="connected ? 'btConnected' : ''"
    @click="toggleBTConnection"
  >
    <img
      class="smallIcon"
      src="@/assets/img/bluetoothOff.png"
      alt="bluetoothIcon"
    />
  </div>
</template>

<script>
import { mapState, mapGetters } from "vuex";

export default {
  name: "BTButton",
  data() {
    return {
      options: {
        namePrefix: "Honk", // Name of the device to look for
        services: null // Service to look for
      }
    };
  },
  mounted() {
    this.options.services = [this.serviceUUID]; // Assign the service Id we are looking to the options we are looking for.
  },
  computed: {
    ...mapState({
      devices: state => state.webBluetooth.devices,
      deviceID: state => state.webBluetoothState.deviceID,
      serviceUUID: state => state.webBluetoothState.serviceUUID
    }),
    ...mapGetters({
      device: "webBluetooth/device", // Library getter for getting the a device based on the ID
      deviceServices: "webBluetooth/servicesForDevice"
    }),
    deviceOptions() {
      let deviceFromID = this.device(this.deviceID);
      return {
        device: deviceFromID
      };
    },
    connected() {
      // Method that returns a boolean based on whether we are connected to to a device. This is determined by the device ID and then the object gatt property
      if (this.deviceID !== "") {
        return this.device(this.deviceID).gatt.connected;
      } else {
        return false;
      }
    }
  },
  methods: {
    toggleBTConnection() {
      if (!this.connected) {
        this.connect();
      } else {
        this.disconnect();
      }
    },
    connect() {
      this.$store
        .dispatch("webBluetooth/addDevice", this.options) // Find the device we are looking for with the provided options.
        .then(() => {
          let deviceID = "";
          for (let device of this.devices) {
            // Go through all devices in webBluetooth devices state
            if (device.name.startsWith(this.options.namePrefix)) {
              // Find the first one that starts with our prefix.
              deviceID = device.id; // Get its ID
            }
          }
          this.$store.dispatch("webBluetoothState/setDeviceID", { deviceID }); // Dispatch the ID to the store for global access
          this.$store
            .dispatch("webBluetooth/connectDevice", this.deviceOptions) // Make a Connection to the Bluetooth Device TODO: this only works on the second attempt when first connecting for some reason, fix this.
            .then(() => {
              // console.log(this.devices);
              this.$store.dispatch(
                "webBluetooth/discoverServices",
                this.deviceOptions
              ); // Find the Service of our BLE device and save it and the characteristics in the store
            });
        });
    },
    disconnect() {
      this.$store
        .dispatch("webBluetooth/disconnectDevice", this.deviceOptions) // Let the store do the disconnect.
        .then(() => {
          let deviceID = "";
          this.$store.dispatch("webBluetoothState/setDeviceID", { deviceID }); // Update the device ID in the store.
        });
    }
  }
};
</script>

<style lang="scss">
.btConnected {
  background-color: $bluetoothColor !important;
  &:hover {
    background-color: $bluetoothHover !important;
  }
}
</style>
