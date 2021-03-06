
/*
 * Appcelerator Titanium Mobile
 * Copyright (c) 2011-2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */
var should = require('./should');

describe("Titanium.UI.Windows.CommandBar", function () {
    function isWin() {
       return (Ti.Platform.osname == 'windowsphone' || Ti.Platform.osname == 'windowsstore');
    }

    it("constructor", function (finish) {
        if (!isWin()) return finish();

        should(Ti.UI.Windows).not.be.undefined;
        should(Ti.UI.Windows.createCommandBar).be.a.Function;
        should(Ti.UI.Windows.createAppBarButton).be.a.Function;
        should(Ti.UI.Windows.createAppBarToggleButton).be.a.Function;
        should(Ti.UI.Windows.createAppBarSeparator).be.a.Function;

        finish();
    });

    it("CommandBar", function (finish) {
        if (!isWin()) return finish();

        var bar = Ti.UI.Windows.createCommandBar();
        should(bar).be.an.Object;
        should(bar.items).be.an.Array;

        finish();
    });

    it("AppBarButton", function (finish) {
        if (!isWin()) return finish();

        var button = Ti.UI.Windows.createAppBarButton();
        should(button).be.an.Object;
        should(button.icon).not.be.undefined;
        should(button.touchEnabled).not.be.undefined;
        should(button.touchEnabled).be.a.Boolean;

        finish();
    });

    it("AppBarToggleButton", function (finish) {
        if (!isWin()) return finish();

        var button = Ti.UI.Windows.createAppBarToggleButton();
        should(button).be.an.Object;
        should(button.icon).not.be.undefined;
        should(button.touchEnabled).not.be.undefined;
        should(button.checked).not.be.undefined;
        should(button.touchEnabled).be.a.Boolean;
        should(button.checked).be.a.Boolean;

        finish();
    });


    it("AppBarSeparator", function (finish) {
        if (!isWin()) return finish();

        var separator = Ti.UI.Windows.createAppBarSeparator();
        should(separator).be.an.Object;

        finish();
    });
});
