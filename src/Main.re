/* Express types */
/* Credit for boilerplate: https://medium.com/@kevinsimper/how-to-create-express-js-server-in-reasonml-97ba28173f63 */
type express;
type response;
type handler = (string, response) => unit;
type emptyHandler = unit => unit;
[@bs.send] external get : (express, string, handler) => unit = "";
[@bs.send] external send : (response, string) => unit = "";
[@bs.send] external listen : (express, int, emptyHandler) => unit = "";
[@bs.send] external on : (express, string, emptyHandler) => unit = "";
[@bs.send] external use : (express, emptyHandler) => unit = "";
[@bs.module] external express : unit => express = "express";

/* BodyParser types */
type bodyparser;
[@bs.send] external json : (bodyparser) => emptyHandler = "";
type encodingOption = {
  extended: bool
};
[@bs.send] external urlencoded : (bodyparser, encodingOption) => emptyHandler = "";
[@bs.module] external bodyparser : bodyparser = "body-parser";

let app = express();

/* Setup middlewares */
use(app, urlencoded(bodyparser, {extended: true}))
use(app, json(bodyparser));

get(app, "/", (_, res) => {
  send(res, "hi")
})

let port = 3000;

listen(app, port, () => {
  "Listening on port " ++ Js.Int.toString(port)
    |> Js.log
});



