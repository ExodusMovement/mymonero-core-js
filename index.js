'use strict'

const MyMoneroCoreCppWASM = require('./monero_utils/MyMoneroCoreCpp_WASM.js')

async function loadMyMoneroCore(options) {
  const Module = await MyMoneroCoreCppWASM(options).ready
  return { Module }
}

module.exports = { loadMyMoneroCore }
