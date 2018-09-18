open Express;

/* BodyParser types */
type bodyparser;
[@bs.send] external json: bodyparser => Express.Middleware.t = "";
[@bs.deriving abstract]
type urlEncodedOptions = {extended: bool};
[@bs.send]
external urlencoded: (bodyparser, urlEncodedOptions) => Express.Middleware.t = "";
[@bs.module] external bodyparser: bodyparser = "body-parser";

let app = express();

App.use(app, urlencoded(bodyparser, urlEncodedOptions(~extended=true)));
App.use(app, json(bodyparser));

App.get(app, ~path="/") @@
Middleware.from((_next, _req) => {
  Response.sendString("Hello World");
})

let port = 4000;

let onListen = (_) => Js.log("Server running on port " ++ Js.Int.toString(port));

let server = App.listen(app, ~port, ~onListen, ());
