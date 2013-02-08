/**
 * @name MFT.ApplinkMediaController
 * 
 * @desc Applink Media Controller logic
 * 
 * @category    Controller
 * @filesource  app/controller/applink/ApplinkMediaController.js
 * @version     1.0
 *
 * @author      Andriy Melnyk
 */

MFT.ApplinkMediaController = Em.Object.create({
    
    /**
	 * Current Media application id
	 *
	 * @type {Number}
	 */
	currentAppId: 0,
    
    /**
     * Return current Media application name
     * used for application button
     */
    currentAppName: function() {
        if ( this.currentAppId ) {
            return MFT.ApplinkController.getApplicationModel(this.currentAppId).appName;
        }
    }.property('this.currentAppId'),
    
    /**
     * Return current Media application icon
     * used for application button
     */
    currentAppIcon: function() {
        if ( this.currentAppId ) {
            return MFT.ApplinkController.getApplicationModel(this.currentAppId).appIcon;
        }
    }.property('this.currentAppId','MFT.ApplinkAppController.model.appIcon'),

    /** Call notification OnCommand on UIRPC */
    onCommand: function(element){
       FFW.UI.onCommand(element.commandId, element.appId);
    },

    /** Call notification OnCommandSoftButton on UIRPC */
    onCommandSoftButton: function(element){
       FFW.UI.onCommandSoftButton(element.softButtonID, element.appId);
    },

    /** Switching on Application */
    activateApp: function( applicationModel ){
        
        // store active application id
        this.set( 'currentAppId' , applicationModel.appId);
        
        // set active model
        MFT.ApplinkAppController.set('model',applicationModel);
                
        //FFW.AppLinkCoreClient.ActivateApp( applicationModel.appId );

        MFT.MediaController.listDown();

        MFT.MediaController.turnOnApplink();
        
    },
    
    /**
     * Restore current application to active state
     */
    restoreCurrentApp: function() {

        if ( MFT.ApplinkAppController.model.appId === this.currentAppId ) {
            FFW.AppLinkCoreClient.ActivateApp( this.currentAppId );
            return;
        }
        this.activateApp( MFT.ApplinkController.getApplicationModel( this.currentAppId ) );
    },

    /** Applink perform interaction action from VR */
    onVRPerformInteractionChoosed: function(element){

        if(MFT.States.media.applink.applinkperforminteractionchoise.active){
            FFW.VR.onChoise(element.choiceID);
            MFT.States.back();
        }

    },

    /** Applink perform interaction action */
    onPerformInteractionChoosed: function(element){

        if(MFT.States.media.applink.applinkperforminteractionchoise.active){
            FFW.UI.interactionResponse( "SUCCESS", element.choiceID );
            MFT.States.back();
        }

    }
});