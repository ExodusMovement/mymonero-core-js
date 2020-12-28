'use strict'

const MyMoneroCoreBridgeClass = require('./monero_utils/MyMoneroCoreBridgeClass.js')
const MyMoneroCoreCppWASM = require('./monero_utils/MyMoneroCoreCpp_WASM.js')

async function loadMyMoneroCore(options) {
  const thisModule = await MyMoneroCoreCppWASM(options).ready
  const instance = new MyMoneroCoreBridgeClass(thisModule)
  return instance
}

module.exports = { loadMyMoneroCore }
