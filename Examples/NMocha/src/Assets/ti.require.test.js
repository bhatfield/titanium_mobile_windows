/*
 * Appcelerator Titanium Mobile
 * Copyright (c) 2011-2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */
var should = require('./should');

describe('requireJS', function () {
    // require should be a function
    it('requireJS.Function', function (finish) {
        should(require).be.a.Function;
        finish();
    });

    // require should return object
    it('requireJS.Object', function (finish) {
        var object = require('ti.require.test_test');
        should(object).be.an.Object;
        finish();
    });

    // require for invalid file should throw error
    it('requireJS.NonObject', function (finish) {
        (function () {
            var object = require('requireJS_test_notfound');
            should(object).not.be.an.Object;
        }).should.throw();
        finish();
    });

    // require should cache object
    it.skip('requireJS.ObjectCache', function (finish) {
        var object1 = require('ti.require.test_test');
        var object2 = require('ti.require.test_test');
        should(object1).be.an.Object;
        should(object2).be.an.Object;
        should((object1 ==  object2)).be.true;
        should((object1 === object2)).be.true;
        finish();
    });

    // local function and variable should not be exposed
    it('requireJS.LocalFunc', function (finish) {
        var object = require('ti.require.test_test');
        should(object).be.an.Object;
        should(object.localVariable).be.undefined;
        should(object.localFunction).be.undefined;
        finish();
    });

    // public function with 0 argument
    it('requireJS.PublicFunc0', function (finish) {
        var object = require('ti.require.test_test');
        should(object).be.an.Object;
        should(object.testFunc0).a.Function;
        var result = object.testFunc0();
        should(result).be.a.String;
        should(result).be.eql('testFunc0');
        finish();
    });

    // public function with 1 argument
    it('requireJS.PublicFunc1', function (finish) {
        var object = require('ti.require.test_test');
        should(object).be.an.Object;
        should(object.testFunc1).be.a.Function;
        var result = object.testFunc1('A');
        should(result).be.a.String;
        should(result).be.eql('testFunc1 A');
        finish();
    });

    // public function with 2 arguments
    it('requireJS.PublicFunc2', function (finish) {
        var object = require('ti.require.test_test');
        should(object).be.an.Object;
        should(object.testFunc2).be.a.Function;
        var result = object.testFunc2('A', 'B');
        should(result).be.a.String;
        should(result).be.eql('testFunc2 A B');
        finish();
    });

    // public string variable
    it('requireJS.PulbicStrVar', function (finish) {
        var object = require('ti.require.test_test');
        should(object).be.an.Object;
        should(object.testStrVar).be.a.String;
        should(object.testStrVar).be.eql('testVar0');
        finish();
    });

    // public number variable
    it('requireJS.PulbicNumVar', function (finish) {
        var object = require('ti.require.test_test');
        should(object).be.an.Object;
        should(object.testNumVar).be.a.Number;
        should(object.testNumVar).be.eql(101);
        finish();
    });

    // public boolean variable
    it('requireJS.PulbicBoolVar', function (finish) {
        var object = require('ti.require.test_test');
        should(object).be.an.Object;
        should(object.testBoolVar).be.a.Boolean;
        should(object.testBoolVar).be.true;
        finish();
    });

    // public null variable
    it('requireJS.PulbicNullVar', function (finish) {
        var object = require('ti.require.test_test');
        should(object).be.an.Object;
        should(object.testNullVar).be.null;
        finish();
    });

    // internal __filename
    it('requireJS.__filename', function (finish) {
        var object = require('ti.require.test_test');
        should(object).be.an.Object;
        should(object.filename).be.a.String;
        should(object.filename).be.eql('ti.require.test_test');
        finish();
    });

});
